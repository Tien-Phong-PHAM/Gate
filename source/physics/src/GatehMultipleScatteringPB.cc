/*----------------------
   Copyright (C): OpenGATE Collaboration

This software is distributed under the terms
of the GNU Lesser General  Public Licence (LGPL)
See LICENSE.md for further details
----------------------*/


#include "GatehMultipleScatteringPB.hh"

#include "GateMultiScatteringMessenger.hh"

//-----------------------------------------------------------------------------
GatehMultipleScatteringPB::GatehMultipleScatteringPB():GateVProcess("hMultipleScattering")
{  

  SetDefaultParticle("mu+"); SetDefaultParticle("mu-");
  SetDefaultParticle("tau+"); SetDefaultParticle("tau-");
  SetDefaultParticle("pi+"); SetDefaultParticle("pi-");
  SetDefaultParticle("kaon+"); SetDefaultParticle("kaon-");
  SetDefaultParticle("sigma+"); SetDefaultParticle("sigma-");
  SetDefaultParticle("proton"); SetDefaultParticle("anti_proton");
  SetDefaultParticle("xi-"); SetDefaultParticle("anti_xi-");
  SetDefaultParticle("anti_sigma+"); SetDefaultParticle("anti_sigma-");
  SetDefaultParticle("omega-"); SetDefaultParticle("anti_omega-");
  SetDefaultParticle("deuteron");
  SetDefaultParticle("triton");
  SetDefaultParticle("He3");
  SetDefaultParticle("alpha");
  SetDefaultParticle("GenericIon");
  SetProcessInfo("Multiple Coulomb scattering of charged particles");
  pMessenger = new GateMultiScatteringMessenger(this);  
}
//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
G4VProcess* GatehMultipleScatteringPB::CreateProcess(G4ParticleDefinition *)
{
  return new G4hMultipleScattering(GetG4ProcessName()); 
}
//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
void GatehMultipleScatteringPB::ConstructProcess(G4ProcessManager * manager)
{
  manager->AddProcess(GetProcess(),-1, 1, 1);           
}
//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
bool GatehMultipleScatteringPB::IsApplicable(G4ParticleDefinition * par)
{
  for(unsigned int i=0; i<theListOfDefaultParticles.size(); i++)
      if(par->GetParticleName() == theListOfDefaultParticles[i]) return true;
  return false;
}
//-----------------------------------------------------------------------------


MAKE_PROCESS_AUTO_CREATOR_CC(GatehMultipleScatteringPB)
