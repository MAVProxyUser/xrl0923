#ifndef BSP_TMOTOR_BSP_H
#define BSP_TMOTOR_BSP_H

#ifdef  __TMOTOR_BSP_GLOBALS
#define __TMOTOR_BSP_EXT
#else
#define __TMOTOR_BSP_EXT extern
#endif



//����CANͨ�Ŵ�������λ��CANopen_bsp.c�ļ�
//decode_tMotor()�������жϷ���������


#include "can.h"
#include "cmsis_os.h"


#define TMotor_CAN hcan1

#define position_MIN -12.5f    //��λrad
#define position_MAX 12.5f        
#define velocity_MIN -10.0f    //��λrad/s
#define velocity_MAX 10.0f
#define Torque_MIN -80.0f       //��λNm
#define Torque_MAX 80.0f
#define KP_MIN 0.0f
#define KP_MAX 250.0f
#define KD_MIN 0.0f     
#define KD_MAX 50.0f
#define KI_MIN 0
#define KI_MAX 0.05

#define HIP_MOTOR_OFFSET 0.5330
#define KNEE_MOTOR_OFFSET 0.6570


/// CAN Reply Packet Structure ///
/// 16 bit position, between -4*pi and 4*pi
/// 12 bit velocity, between -30 and + 30 rad/s
/// 12 bit current, between -40 and 40;

//t-motor CAN-ID����
typedef enum
{
	LEFT_HIP_MOTOR_ID = 0x01,
	LEFT_KNEE_MOTOR_ID = 0x03,
	RIGHT_HIP_MOTOR_ID = 0x08,
	RIGHT_KNEE_MOTOR_ID = 0x09,
	test_ID = 0x10
	
} HipMotorID_TypeDef;

//t-motor ģʽ�����data[7]
typedef enum
{
	TMotor_Control_Mode = 0xFC,
	TMotor_Reset_Mode = 0xFD,
	TMotor_Set_Zore = 0xFE
	
} TMotor_Mode_TypeDef;


typedef struct
{
	
	TMotor_Mode_TypeDef motor_mode;
	uint8_t id;
	uint16_t fault;
	//assemble bias
	float assemble_bias;
	//speed cliff
	float speed_max;
	//reference data
    float ref_position;
    float ref_torque;
    //current feedback data
	float curr_position;
	float curr_speed_radps;
	float curr_torque;
    //parameter of PID
	float Kp_theta;
	float Kd_theta;
	float Kp_v;
	float Ki_v;
	float Kd_v;

	
 
} tmotor_handle_t;

__TMOTOR_BSP_EXT tmotor_handle_t leftHip_Motor;
__TMOTOR_BSP_EXT tmotor_handle_t leftKnee_Motor;
__TMOTOR_BSP_EXT tmotor_handle_t rightHip_Motor;
__TMOTOR_BSP_EXT tmotor_handle_t rightKnee_Motor;

__TMOTOR_BSP_EXT tmotor_handle_t test_Motor;



//functions declaration
void tmotor_init(tmotor_handle_t* m, uint8_t id,\
				  float assemble_bias, \
				  float speed_max, \
				  float Kp_theta, float Kd_theta,\
				  float Kp_v, float Ki_v, float Kd_v);

void pkg_tmotor_init(void);
void TMotor_setMode(HipMotorID_TypeDef tID, TMotor_Mode_TypeDef tMode);

void leftHipMotor_setPosition(float p_des, float kp);
void rightHipMotor_setPosition(float p_des, float kp);

void tmotor_set_position(uint8_t id, float p_des, float kp);
void tmotor_pkg_cmd(HipMotorID_TypeDef tID,float p_des, float v_des, float kp, float kd, float t_ff);
void tmotor_serial_mode_send_cmd(HipMotorID_TypeDef tID,float p_des, float v_des, \
								 float kp_p, float kd_p, \
								 float kp_v, float kd_v, float ki_v);

void unpackCanInfoFromMotor(uint8_t* data, tmotor_handle_t* motor);
void test_motor_set_position(float p_des, float kp);

float fmaxf(float x, float y);
float fminf(float x, float y);
int float_to_uint(float x, float x_min, float x_max, int bits);
float uint_to_float(int x_int, float x_min, float x_max, int bits);

#endif