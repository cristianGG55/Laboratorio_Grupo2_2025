#include "../../includes/includelib.h"
#include "../localidad/localidad.h"
#include "../cliente/cliente.h"
#include "../banco/banco.h"
#include "../medio_pago/medio_pago.h"
#include "../factura/factura.h"

#include "compra.h"

THIS(obj_Compra)// crea definicion de funcion this para este modulo. .. Macro en config.h

//----------------------------------------------------
static void toString_CompraImpl(void *self)
{
     obj_Compra *obj=this(self);      
     // version con algunos datos, ver como gestionar la posibilidad de listar mas informacion.
     printf("\n"); 
}

static int getCodigoCompra_Impl(void *self)
{ return  *((int *) getValue(self,POS_CODIGO_COM));}
//----------------------------------------------------

static char * getFechaCompra_Impl(void *self)
{ return  (char *) getValue(self,POS_FECHA_COM);}
//----------------------------------------------------

static bool getEntregadoCompra_Impl(void *self)
{ return  *((bool *) getValue(self,POS_ENTREGADO_COM));}
//----------------------------------------------------

static int getCodFacturaCompra_Impl(void *self)
{ return  *((int *) getValue(self,POS_COD_FACTURA_COM));}
//----------------------------------------------------


static void setCodigoCompra_Impl(void *self,int val)
{ setValue(self,POS_CODIGO_COM,&val); }
//----------------------------------------------------

static void setFechaCompra_Impl(void *self,char * val)
{ setValue(self,POS_FECHA_COM,val); }
//----------------------------------------------------

static void setEntregadoCompra_Impl(void *self,bool val)
{ setValue(self,POS_ENTREGADO_COM,&val); }
//----------------------------------------------------

static void setCodFacturaCompra_Impl(void *self,int val)
{ setValue(self,POS_COD_FACTURA_COM,&val); }
//----------------------------------------------------

//----------------------------------------------------
static void destroyInternalCOM_Impl(void *self)
{
	obj_Compra *obj = this(self);	
	// finalizar cada referencia inicializada - no NULL
}
//----------------------------------------------------
//implementacion de relaciones
//----------------------------------------------------
obj_Factura *getCompra_FacturaObj_Impl(void *self)
{
 obj_Compra *obj = this(self);        //acceso a la informacion relacionada   return NULL;
}
//----------------------------------------------------
//implementacion constructor
//----------------------------------------------------
static void *init_Compra(void *self)
{
  obj_Compra *obj      = this(self);
  obj->ds  			    = &table_Compra;
  obj->constructor 	    = Compra_new;
  obj->sizeObj 		    = sizeof(obj_Compra*);
  // inicializar cada puntero a una referencia relacionada, para ver cuando se busca por el id..
    obj->factura   = NULL;

  //incializacion de la interfaz de la entidad
  obj->toString    		= toString_CompraImpl;
  // Inicializar handlers de getters y setters
  /// getters
    
	obj->getCodigo = getCodigoCompra_Impl;
  
	obj->getFecha = getFechaCompra_Impl;
  
	obj->getEntregado = getEntregadoCompra_Impl;
  
	obj->getCodFactura = getCodFacturaCompra_Impl;

  /// setters  
    
	obj->setCodigo = setCodigoCompra_Impl;
  
	obj->setFecha = setFechaCompra_Impl;
  
	obj->setEntregado = setEntregadoCompra_Impl;
  
	obj->setCodFactura = setCodFacturaCompra_Impl;

  // implementar detroy internal para liberar recursos  
  obj->destroyInternal 	= destroyInternalCOM_Impl;
  //---- acceso a relaciones  
    obj->getFacturaObj  = getCompra_FacturaObj_Impl;

  return obj;
}
//----------------------------------------------------
//constructor de Compra
obj_Compra *Compra_new()
{
  return (obj_Compra *)init_obj(sizeof(obj_Compra), init_Compra);
}
//----------------------------------------------------

