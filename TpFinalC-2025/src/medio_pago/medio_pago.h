#ifndef MEDIO_PAGO_INCLUDED
	#define MEDIO_PAGO_INCLUDED
	#define CNT_COL_MEDIO_PAGO 3
	#define POS_CODIGO_MED 0
	#define POS_DESCRIPCION_MED 1
	#define POS_COD_BANCO_MED 2

	//----------------------------------------------------
	typedef struct {
		IOBJECT	 // crea definicion de propiedades comunes a Object .. Macro en orm.h     
	    //-- getters
        
	getPropertyIntPtr   getCodigo;
        
	getPropertyCharPtr   getDescripcion;
        
	getPropertyIntPtr   getCodBanco;

	    //-- setters
        
	setPropertyIntPtr   setCodigo;
        
	setPropertyCharPtr   setDescripcion;
        
	setPropertyIntPtr   setCodBanco;

// getter de objeto relacionado
        getBancoObjPtr  getBancoObj;
        obj_Banco *banco;

	}obj_MedioPago;
	// funcionalidad publica que se implementa en MedioPago.c
	extern obj_MedioPago *MedioPago_new ();
	// meta data para acceder a las MedioPagos - definicion de las columnas de la tabla
	static Column cols_MedioPago[CNT_COL_MEDIO_PAGO]=
	{ 
	//definicion del mapeo, por cada columna de la tabla con los atributos del pseudobjeto.
	// nombre de la columna, tipo, tamaño, si es clave, si es autonumerado.
    
	{"codigo",t_int,sizeof(int),true,true},
    
	{"descripcion",t_varchar,(sizeof(char)*MAX50)+1,false,false},    
	{"cod_banco",t_int,sizeof(int),false,false},

	};
	// plantilla para la MedioPago.
	static Table table_MedioPago={"medio_pago",CNT_COL_MEDIO_PAGO,0, cols_MedioPago,NULL};
	// generar PunteroGenerico para usar puntero funcion que obtenga pseudoObjeto MedioPago
	typedef obj_MedioPago *(*getMedioPagoObjPtr)(void *self);
#endif
