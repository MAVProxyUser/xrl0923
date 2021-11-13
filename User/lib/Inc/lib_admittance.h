#ifndef __LIB_ADMITTANCE_H
#define __LIB_ADMITTANCE_H

#include "main.h"
#include "lib_impd.h"

typedef struct __ramp_t
{
    float src;        //��������
    float dest;       //�������
    float rate;			//�ٶ�
    float min_value;    //�޷���Сֵ
    float max_value;    //�޷����ֵ
    float output;

}ramp_t;

typedef struct __admittance_t
{
	uint8_t init_sign;
	uint8_t init_time;
	float x0;  		//ƽ��λ��
	float dot_x0; 	//ƽ����ٶ�
	float xf;  		//���������
	float dot_xf;	//�������ٶ�
	float ed;  		//�������

	float f_ext;   	//�����
	float dot_ed;  	//�����ٶ�

	float Md; //���ɿ��ƹ���ϵ��
	float Bd; //���ɿ�������ϵ��
	float Kd; //���ɿ��Ƹն�ϵ��

	float delte_t;  //���ʱ��
    float deadband; //err < deadband return 0

    float MaxOutput; //����޷�

    uint32_t process_time_interval;
    uint32_t access_time_now;
    uint32_t access_time_last;

}admittance_t;

extern admittance_t admt_x_diff, admt_y_diff;
extern admittance_t admt_left_x_diff, admt_left_x_diff_2;
extern admittance_t admt_left_y_diff, admt_left_y_diff_2;
extern admittance_t admt_right_x_diff, admt_right_x_diff_2;
extern admittance_t admt_right_y_diff, admt_right_y_diff_2;

void admittance_struct_init(admittance_t* admt, float Kd, float Bd, float MaxOutput, float deadband);
float admittance_calc(admittance_t* admt, float f_ext, float x0); //���x_fҪ�г�ʼֵ����������x_f����x0
float admittance_calc2(admittance_t* admt, float f_ext, float x0, float dot_x0, uint32_t t_now);
float ramp_calc(ramp_t *rp, float src, float dest);
void admt_param_change(void);
void admit_params_init(void);

#endif
