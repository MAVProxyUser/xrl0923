#ifndef __LIB_IMPED_H
#define __LIB_IMPED_H

#include "main.h"
#define ABS(x) ((x>0)? (x): (-x))

typedef struct __impedance_t
{
    float Kp;
    float Kd;

    float set;				//Ŀ��ֵ
    float get;				//����ֵ
    float err;				//���

    float d_set;				//Ŀ��ֵ
    float d_get;				//����ֵ
    float d_err;				//���


    float pout;							//p���
    float dout;							//d���

    float pos_out;						//����λ��ʽ���
    float last_pos_out;				//�ϴ����

    float max_err;
    float deadband;				//err < deadband return

    long unsigned int MaxOutput;				//����޷�

}impedance_t;

void impedance_struct_init(impedance_t* impd, float Kp, float Kd, long unsigned int max, float deadband);
void abs_limit(float *a, float ABS_MAX,float offset);
float impedance_calc(impedance_t* impd, float get, float set, float d_get, float d_set);
void impedance_control(void);

#endif
