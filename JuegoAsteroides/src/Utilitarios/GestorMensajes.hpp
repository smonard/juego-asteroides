#ifndef GESTORMENSAJES_HPP
#define GESTORMENSAJES_HPP

#define RUTA_TIPOGRAFIA "/System/Library/Fonts/Menlo.ttc" 
#include "../Base/CoreLib.h"

class GestorMensajes
{
    Tipografia *font;
    Color * color;
    
public:

    GestorMensajes()
    {
        font = CoreLib::obtenerInstancia()->cargarFuente(RUTA_TIPOGRAFIA, 24);
        color = new Color(0,0,0,0);
    }
    
    void dibujarTexto(string texto, PosicionPantalla posicion){
        CoreLib::obtenerInstancia()->dibujarTexto(font, color, texto, posicion);
    }
    
    ~GestorMensajes()
    {
        delete font;
        delete color;
    }

};

#endif // GESTORMENSAJES_HPP
