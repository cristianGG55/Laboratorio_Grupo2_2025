#ifndef DET_FACTURA_INCLUDED
	#define DET_FACTURA_INCLUDED
	#define CNT_COL_DET_FACTURA 5
	#define POS_COD_FACTURA_DET 0
	#define POS_RENGLON_DET 1
	#define POS_COD_PRODUCTO_DET 2
	#define POS_PRECIO_UNIT_DET 3
	#define POS_CANTIDAD_DET 4

	//----------------------------------------------------
	typedef struct {
		IOBJECT	 // crea definicion de propiedades comunes a Object .. Macro en orm.h     
	    //-- getters
        
	getPropertyIntPtr   getCodFactura;
        
	getPropertyIntPtr   getRenglon;
        
	getPropertyIntPtr   getCodProducto;
        
	getPropertyFloatPtr   getPrecioUnit;
        
	getPropertyIntPtr   getCantidad;

	    //-- setters
        
	setPropertyIntPtr   setCodFactura;
        
	setPropertyIntPtr   setRenglon;
        
	setPropertyIntPtr   setCodProducto;
        
	setPropertyFloatPtr   setPrecioUnit;
        
	setPropertyIntPtr   setCantidad;

// getter de objeto relacionado
        getFacturaObjPtr  getFacturaObj;
        obj_Factura *factura;
        getProductoObjPtr  getProductoObj;
        obj_Producto *producto;

	}obj_DetFactura;
	// funcionalidad publica que se implementa en DetFactura.c
	extern obj_DetFactura *DetFactura_new ();
	// meta data para acceder a las DetFacturas - definicion de las columnas de la tabla
	static Column cols_DetFactura[CNT_COL_DET_FACTURA]=
	{ 
	//definicion del mapeo, por cada columna de la tabla con los atributos del pseudobjeto.
	// nombre de la columna, tipo, tamaño, si es clave, si es autonumerado.
    
	{"cod_factura",t_int,sizeof(int),true,false},
    
	{"renglon",t_int,sizeof(int),true,false},
    
	{"cod_producto",t_int,sizeof(int),false,false},
    
	{"precio_unit",t_float,sizeof(float),false,false},
    
	{"cantidad",t_int,sizeof(int),false,false},

	};
	// plantilla para la DetFactura.
	static Table table_DetFactura={"det_factura",CNT_COL_DET_FACTURA,0, cols_DetFactura,NULL};
	// generar PunteroGenerico para usar puntero funcion que obtenga pseudoObjeto DetFactura
	typedef obj_DetFactura *(*getDetFacturaObjPtr)(void *self);
#endif
