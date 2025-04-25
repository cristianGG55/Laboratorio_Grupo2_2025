#ifndef BULTO_INCLUDED
	#define BULTO_INCLUDED
	#define CNT_COL_BULTO 6
	#define POS_CODIGO_BUL 0
	#define POS_FECHA_DESPACHO_BUL 1
	#define POS_FECHA_LLEGADA_BUL 2
	#define POS_HORA_LLEGADA_BUL 3
	#define POS_ESTADO_BUL 4
	#define POS_COD_FACTURA_BUL 5

	//----------------------------------------------------
	typedef struct {
		IOBJECT	 // crea definicion de propiedades comunes a Object .. Macro en orm.h     
	    //-- getters
        
	getPropertyIntPtr   getCodigo;
        
	getPropertyCharPtr   getFechaDespacho;
        
	getPropertyCharPtr   getFechaLlegada;
        
	getPropertyCharPtr   getHoraLlegada;
        
	getPropertyIntPtr   getEstado;
        
	getPropertyIntPtr   getCodFactura;

	    //-- setters
        
	setPropertyIntPtr   setCodigo;
        
	setPropertyCharPtr   setFechaDespacho;
        
	setPropertyCharPtr   setFechaLlegada;
        
	setPropertyCharPtr   setHoraLlegada;
        
	setPropertyIntPtr   setEstado;
        
	setPropertyIntPtr   setCodFactura;

// getter de objeto relacionado
        getFacturaObjPtr  getFacturaObj;
        obj_Factura *factura;

	}obj_Bulto;
	// funcionalidad publica que se implementa en Bulto.c
	extern obj_Bulto *Bulto_new ();
	// meta data para acceder a las Bultos - definicion de las columnas de la tabla
	static Column cols_Bulto[CNT_COL_BULTO]=
	{ 
	//definicion del mapeo, por cada columna de la tabla con los atributos del pseudobjeto.
	// nombre de la columna, tipo, tamaño, si es clave, si es autonumerado.
    
	{"codigo",t_int,sizeof(int),true,true},    
	{"fecha_despacho",t_varchar,(sizeof(char)*MAX10)+1,false,false},    
	{"fecha_llegada",t_varchar,(sizeof(char)*MAX10)+1,false,false},    
	{"hora_llegada",t_varchar,(sizeof(char)*MAX5)+1,false,false},    
	{"estado",t_int,sizeof(int),false,false},    
	{"cod_factura",t_int,sizeof(int),false,false},

	};
	// plantilla para la Bulto.
	static Table table_Bulto={"bulto",CNT_COL_BULTO,0, cols_Bulto,NULL};
	// generar PunteroGenerico para usar puntero funcion que obtenga pseudoObjeto Bulto
	typedef obj_Bulto *(*getBultoObjPtr)(void *self);
#endif
