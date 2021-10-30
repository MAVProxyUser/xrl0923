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
	float x0;  //����ǰ����
	float dx0; //����ǰ�ٶ�
	float xf;  //���������
	float ed;  //�������

	float f_ext;   //�����
	float dot_ed;  //���Ŀ������

	float Md; //���ɿ��ƹ���ϵ��
	float Bd; //���ɿ�������ϵ��
	float Kd; //���ɿ��Ƹն�ϵ��

	float delte_t;  //���ʱ��
    float deadband; //err < deadband return 0

    float MaxOutput; //����޷�

}admittance_t;

void admittance_struct_init(admittance_t* admt, float Kd, float Bd, float MaxOutput, float deadband);
float admittance_calc(admittance_t* admt, float f_ext, float x0, float dx0); //���x_fҪ�г�ʼֵ����������x_f����x0
float ramp_calc(ramp_t *rp, float src, float dest);

#endif
