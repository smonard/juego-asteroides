#include "FabricaObjetoGrafica.h"


FabricaObjetoGrafica* FabricaObjetoGrafica::instancia = 0;


FabricaObjetoGrafica::FabricaObjetoGrafica()
{
}

FabricaObjetoGrafica* FabricaObjetoGrafica::obtenerInstancia()
{
    if (instancia == 0) {
        instancia = new FabricaObjetoGrafica();
    }
    return instancia;
}

void FabricaObjetoGrafica::liberarse()
{
    if (instancia) {
        delete instancia;
    }
    instancia = 0;
}

ObjetoGraficoInterfaz* FabricaObjetoGrafica::crearObjetoVisual(actorEnum actor_a_crear, PosicionPantalla nposicion, Color * ncolor)
{
    ObjetoGraficoInterfaz* objeto = NULL;
    switch(actor_a_crear)
    {
        case asteroide:
            objeto = new Asteroide(nposicion, ncolor);
        break;
        case naveEspacial:
            objeto = new NaveEspacial(nposicion, ncolor);
        break;
        case rayoLaser :
            objeto = new RayoLaser(nposicion, ncolor);
        break;
    }
    return objeto;
}

bool FabricaObjetoGrafica::esDeTipo(actorEnum actor_tipo, ObjetoGraficoInterfaz* objetoAdeterminar){
    switch(actor_tipo)
    {
        case asteroide:
            return dynamic_cast<Asteroide*> ((objetoAdeterminar) ) != NULL;
        case naveEspacial:
            return dynamic_cast<NaveEspacial*> ((objetoAdeterminar) ) != NULL;
        case rayoLaser :
            return dynamic_cast<RayoLaser*> ((objetoAdeterminar) ) != NULL;
        default:
        return false;
    }
}

FabricaObjetoGrafica::~FabricaObjetoGrafica()
{
}
