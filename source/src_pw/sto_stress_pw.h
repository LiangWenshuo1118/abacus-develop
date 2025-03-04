#ifndef STO_STRESS_PW_H
#define STO_STRESS_PW_H

#include "stress_func.h"
#include "./sto_wf.h"
//qianrui create 2021-6-4

class Sto_Stress_PW:public Stress_Func
{
	public :
	
	Sto_Stress_PW (){};
	~Sto_Stress_PW (){};

	//calculate the stress in PW basis
	void cal_stress(ModuleBase::matrix& sigmatot,const psi::Psi<complex<double>>* psi_in, Stochastic_WF& stowf);

	private :
	void sto_stress_kin(ModuleBase::matrix&, const psi::Psi<complex<double>>* psi_in, Stochastic_WF& stowf);
	void sto_stress_nl(ModuleBase::matrix&, const psi::Psi<complex<double>>* psi_in, Stochastic_WF& stowf);
	


};
#endif
