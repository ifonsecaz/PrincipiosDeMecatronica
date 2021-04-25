#! /usr/bin/env python

import rospy
from geometry_msgs.msg import Twist
from turtlesim.msg import Pose
import math
import time
from std_srvs.srv import Empty

x = 0
y = 0
z = 0
theta = 0

def poseCallback(pose_message):
    global x
    global y
    global z
    global theta
    
    x = pose_message.x
    y = pose_message.y
    theta = pose_message.theta

def orientate (xgoal, ygoal):
    
	global x
	global y
	global theta

	velocity_message = Twist()
	cmd_vel_topic = '/turtle1/cmd_vel'

	while(True):
		ka = 1
		desired_angle_goal = math.atan2(ygoal-y, xgoal-x)
		
		if desired_angle_goal < 0:
			desired_angle_goal = desired_angle_goal + 2*math.pi
			#dtheta = desired_angle_goal - theta
			#print ('theta=', theta)			
			#print ('new_angle=', desired_angle_goal)
		else:
			desired_angle_goal = desired_angle_goal
			#dtheta = desired_angle_goal - theta	
			#print ('new_angle=', desired_angle_goal)
		if theta<0:
			theta=2*math.pi+theta
		dtheta = desired_angle_goal - theta

		#if abs(desired_angle_goal - theta) < abs((desired_angle_goal + 2*math.pi) - theta):	
		#	dtheta = desired_angle_goal - theta
		#	print ('dtheta=', dtheta)
		#else:
		#	dtheta = desired_angle_goal + 2*math.pi - theta
		#	print ('dtheta=', dtheta)        
		#
		if (abs(dtheta) < 0.01):
			print ('angle', theta*360.00/6.2831, 'reached')
			time.sleep(1)
			break

		angular_speed = ka * dtheta

		velocity_message.linear.x = 0.0
		velocity_message.angular.z = angular_speed
		velocity_publisher.publish(velocity_message)
		#print ('x=', x, 'y=', y)

        
def go_to_goal (xgoal, ygoal):
	    	
	global x
	global y
	global theta

	velocity_message = Twist()
	cmd_vel_topic = '/turtle1/cmd_vel'

         
	while(True):

		ka = 5.0
		desired_angle_goal = math.atan2(ygoal+0.01-y, xgoal+0.01-x)
		#print ('desired_angle=', desired_angle_goal)

		if (desired_angle_goal < 0.0):	
			desired_angle_goal = desired_angle_goal + 6.2831
			#print ('new_angle=', desired_angle_goal)
		else:
			desired_angle_goal = desired_angle_goal	
			#print ('new_angle=', desired_angle_goal)

		dtheta = desired_angle_goal-theta
		#print ('dtheta=', dtheta)        
		angular_speed = ka * (dtheta)	
		

		if (abs(angular_speed) < 0.5):	
			angular_speed = angular_speed
		else:
			angular_speed = 0.0

		kv = 1.2	
		distance = abs(math.sqrt(((xgoal-x)**2)+((ygoal-y)**2)))
		linear_speed = kv * distance

		if (distance < 0.1):
		    print ('point (', x, ',',  y, ') reached')
		    time.sleep(1)
		    break        

		velocity_message.linear.x = linear_speed
		velocity_message.angular.z = angular_speed
		velocity_publisher.publish(velocity_message)
		#print ('x=', x, 'y=', y)

        

if __name__ == '__main__':
	try:

		rospy.init_node('turtlesim_motion_pose', anonymous = True)

		cmd_vel_topic = '/turtle1/cmd_vel'
		velocity_publisher = rospy.Publisher(cmd_vel_topic, Twist, queue_size = 10)

		position_topic = "/turtle1/pose"
		pose_subscriber = rospy.Subscriber(position_topic, Pose, poseCallback)

		
		x0=10.5
		y0=5.5
		
		segmentos=180
		angulo=360/segmentos
		inicio=(180-angulo)/2
		distancia=5*math.sin(math.radians(angulo))/math.sin(math.radians(inicio))
		
		for i in range (segmentos):
			giro=inicio+2*angulo+(i-1)*angulo
			aX=distancia*math.cos(math.radians(giro))
			aY=distancia*math.sin(math.radians(giro))
			posX=x0+aX
			posY=y0+aY
			
			orientate(posX,posY)
			time.sleep(0.1)
			go_to_goal(posX,posY)
			time.sleep(0.1)
			
			x0=posX
			y0=posY

	except rospy.ROSInterruptException:        
		pass
