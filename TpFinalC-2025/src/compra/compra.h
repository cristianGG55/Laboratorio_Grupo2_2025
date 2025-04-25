#ifndef COMPRA_INCLUDED
	#define COMPRA_INCLUDED
	#define CNT_COL_COMPRA 4
	#define POS_CODIGO_COM 0
	#define POS_FECHA_COM 1
	#define POS_ENTREGADO_COM 2
	#define POS_COD_FACTURA_COM 3

	//----------------------------------------------------
	typedef struct {
		IOBJECT	 // crea definicion de propiedades comunes a Object .. Macro en orm.h     
	    //-- getters
        
	getPropertyIntPtr   getCodigo;
        
	getPropertyCharPtr   getFecha;
        
	getPropertyBoolPtr   getEntregado;
        
	getPropertyIntPtr   getCodFactura;

	    //-- setters
        
	setPropertyIntPtr   setCodigo;
        
	setPropertyCharPtr   setFecha;
        
	setPropertyBoolPtr   setEntregado;
        
	setPropertyIntPtr   setCodFactura;

// getter de objeto relacionado
        getFacturaObjPtr  getFacturaObj;
        obj_Factura *factura;

	}obj_Compra;
	// funcionalidad publica que se implementa en Compra.c
	extern obj_Compra *Compra_new ();
	// meta data para acceder a las Compras - definicion de las columnas de la tabla
	static Column cols_Compra[CNT_COL_COMPRA]=
	{ 
	//definicion del mapeo, por cada columna de la tabla con los atributos del pseudobjeto.
	// nombre de la columna, tipo, tamaño, si es clave, si es autonumerado.
    
	{"codigo",t_int,sizeof(int),true,true},
    
	{"fecha",t_varchar,(sizeof(char)*MAX10)+1,false,false},    
	{"entregado",t_bool,sizeof(bool),false,false},
    
	{"cod_factura",t_int,sizeof(int),false,false},

	};
	// plantilla para la Compra.
	static Table table_Compra={"compra",CNT_COL_COMPRA,0, cols_Compra,NULL};
	// generar PunteroGenerico para usar puntero funcion que obtenga pseudoObjeto Compra
	typedef obj_Compra *(*getCompraObjPtr)(void *self);
#endif
