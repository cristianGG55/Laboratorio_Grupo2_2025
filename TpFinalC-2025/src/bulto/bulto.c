#include "../../includes/includelib.h"
#include "../localidad/localidad.h"
#include "../cliente/cliente.h"
#include "../banco/banco.h"
#include "../medio_pago/medio_pago.h"
#include "../factura/factura.h"

#include "bulto.h"

THIS(obj_Bulto)// crea definicion de funcion this para este modulo. .. Macro en config.h

//----------------------------------------------------
static void toString_BultoImpl(void *self)
{
     obj_Bulto *obj=this(self);      
     // version con algunos datos, ver como gestionar la posibilidad de listar mas informacion.
     printf("\n"); 
}

static int getCodigoBulto_Impl(void *self)
{ return  *((int *) getValue(self,POS_CODIGO_BUL));}
//----------------------------------------------------

static char * getFechaDespachoBulto_Impl(void *self)
{ return  (char *) getValue(self,POS_FECHA_DESPACHO_BUL);}
//----------------------------------------------------

static char * getFechaLlegadaBulto_Impl(void *self)
{ return  (char *) getValue(self,POS_FECHA_LLEGADA_BUL);}
//----------------------------------------------------

static char * getHoraLlegadaBulto_Impl(void *self)
{ return  (char *) getValue(self,POS_HORA_LLEGADA_BUL);}
//----------------------------------------------------

static int getEstadoBulto_Impl(void *self)
{ return  *((int *) getValue(self,POS_ESTADO_BUL));}
//----------------------------------------------------

static int getCodFacturaBulto_Impl(void *self)
{ return  *((int *) getValue(self,POS_COD_FACTURA_BUL));}
//----------------------------------------------------


static void setCodigoBulto_Impl(void *self,int val)
{ setValue(self,POS_CODIGO_BUL,&val); }
//----------------------------------------------------

static void setFechaDespachoBulto_Impl(void *self,char * val)
{ setValue(self,POS_FECHA_DESPACHO_BUL,val); }
//----------------------------------------------------

static void setFechaLlegadaBulto_Impl(void *self,char * val)
{ setValue(self,POS_FECHA_LLEGADA_BUL,val); }
//----------------------------------------------------

static void setHoraLlegadaBulto_Impl(void *self,char * val)
{ setValue(self,POS_HORA_LLEGADA_BUL,val); }
//----------------------------------------------------

static void setEstadoBulto_Impl(void *self,int val)
{ setValue(self,POS_ESTADO_BUL,&val); }
//----------------------------------------------------

static void setCodFacturaBulto_Impl(void *self,int val)
{ setValue(self,POS_COD_FACTURA_BUL,&val); }
//----------------------------------------------------

//----------------------------------------------------
static void destroyInternalBUL_Impl(void *self)
{
	obj_Bulto *obj = this(self);	
	// finalizar cada referencia inicializada - no NULL
}
//----------------------------------------------------
//implementacion de relaciones
//----------------------------------------------------
obj_Factura *getBulto_FacturaObj_Impl(void *self)
{
 obj_Bulto *obj = this(self);        //acceso a la informacion relacionada   return NULL;
}
//----------------------------------------------------
//implementacion constructor
//----------------------------------------------------
static void *init_Bulto(void *self)
{
  obj_Bulto *obj      = this(self);
  obj->ds  			    = &table_Bulto;
  obj->constructor 	    = Bulto_new;
  obj->sizeObj 		    = sizeof(obj_Bulto*);
  // inicializar cada puntero a una referencia relacionada, para ver cuando se busca por el id..
    obj->factura   = NULL;

  //incializacion de la interfaz de la entidad
  obj->toString    		= toString_BultoImpl;
  // Inicializar handlers de getters y setters
  /// getters
    
	obj->getCodigo = getCodigoBulto_Impl;
  
	obj->getFechaDespacho = getFechaDespachoBulto_Impl;
  
	obj->getFechaLlegada = getFechaLlegadaBulto_Impl;
  
	obj->getHoraLlegada = getHoraLlegadaBulto_Impl;
  
	obj->getEstado = getEstadoBulto_Impl;
  
	obj->getCodFactura = getCodFacturaBulto_Impl;

  /// setters  
    
	obj->setCodigo = setCodigoBulto_Impl;
  
	obj->setFechaDespacho = setFechaDespachoBulto_Impl;
  
	obj->setFechaLlegada = setFechaLlegadaBulto_Impl;
  
	obj->setHoraLlegada = setHoraLlegadaBulto_Impl;
  
	obj->setEstado = setEstadoBulto_Impl;
  
	obj->setCodFactura = setCodFacturaBulto_Impl;

  // implementar detroy internal para liberar recursos  
  obj->destroyInternal 	= destroyInternalBUL_Impl;
  //---- acceso a relaciones  
    obj->getFacturaObj  = getBulto_FacturaObj_Impl;

  return obj;
}
//----------------------------------------------------
//constructor de Bulto
obj_Bulto *Bulto_new()
{
  return (obj_Bulto *)init_obj(sizeof(obj_Bulto), init_Bulto);
}
//----------------------------------------------------

