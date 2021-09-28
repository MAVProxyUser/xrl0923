#ifndef __LIB_WALKING_H
#define __LIB_WALKING_H

#include "main.h"


#define STANCE_PHASE 1
#define SWING_PHASE  0

typedef struct
{
	float T_s;     //��̬����
	float _t;      //��ǰʱ��(��λ)
	float lambda;  //֧����ռ�ձ�
    float _v;       //�ٶ�
    float leg_lift_hight;  //̧�ȸ߶�
    float body_hight;           //����߶�
} walkingPara_TypeDef;



void walkingPara_struct_init(walkingPara_TypeDef* walkpara, float T_s,float _t,float lambda,float _v,float leg_lift_hight,float body_hight);
void troting(float* x_ref,float* y_ref, float time, walkingPara_TypeDef walkpara);
float Interpolate_cubicBezier(float y0, float yf, float x);
float sature(float value,float maxvalue,float minvalue);

#endif
