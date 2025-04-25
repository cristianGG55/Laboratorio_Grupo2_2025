#ifndef SUCURSALD_INCLUDED
	#define SUCURSALD_INCLUDED
	#define CNT_COL_SUCURSALD 3
	#define POS_COD_SUC_O_SUC 0
	#define POS_COD_SUC_D_SUC 1
	#define POS_KM_SUC 2

	//----------------------------------------------------
	typedef struct {
		IOBJECT	 // crea definicion de propiedades comunes a Object .. Macro en orm.h     
	    //-- getters
        
	getPropertyIntPtr   getCodSucO;
        
	getPropertyIntPtr   getCodSucD;
	
	getPropertyIntPtr   getKm;

	    //-- setters
        
	setPropertyIntPtr   setCodSucO;
        
	setPropertyIntPtr   setCodSucD;
	
	setPropertyIntPtr   setKm;

// getter de objeto relacionado
        getSucursalObjPtr  getSucursalObjO;
        obj_Sucursal *sucursal_o;
        getSucursalObjPtr  getSucursalObjD;
        obj_Sucursal *sucursal_d;

	}obj_SucursalDest;
	// funcionalidad publica que se implementa en SucursalDest.c
	extern obj_SucursalDest *SucursalDest_new ();
	// meta data para acceder a las SucursalDests - definicion de las columnas de la tabla
	static Column cols_SucursalDest[CNT_COL_SUCURSALD]=
	{ 
	//definicion del mapeo, por cada columna de la tabla con los atributos del pseudobjeto.
	// nombre de la columna, tipo, tamaño, si es clave, si es autonumerado.
    
	{"cod_suc_o",t_int,sizeof(int),true,false},
    
	{"cod_suc_d",t_int,sizeof(int),true,false},
	
	{"km",t_int,sizeof(int),false,false},

	};
	// plantilla para la SucursalDest.
	static Table table_SucursalDest={"sucursal_dest",CNT_COL_SUCURSALD,0, cols_SucursalDest,NULL};
	// generar PunteroGenerico para usar puntero funcion que obtenga pseudoObjeto SucursalDest
	typedef obj_SucursalDest *(*getSucursalDestObjPtr)(void *self);
#endif
