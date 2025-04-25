#ifndef TRACK_VI_INCLUDED
	#define TRACK_VI_INCLUDED
	#define CNT_COL_TRACK_VI 9
	#define POS_CODIGO_TRA 0
	#define POS_COD_SUC_O_TRA 1
	#define POS_COD_SUC_D_TRA 2
	#define POS_COD_BULTO_TRA 3
	#define POS_F_INGRESO_TRA 4
	#define POS_H_INGRESO_TRA 5
	#define POS_F_SALIDA_TRA 6
	#define POS_H_SALIDA_TRA 7
	#define POS_DETALLE_TRA 8

	//----------------------------------------------------
	typedef struct {
		IOBJECT	 // crea definicion de propiedades comunes a Object .. Macro en orm.h     
	    //-- getters
        
	getPropertyIntPtr   getCodigo;
        
	getPropertyIntPtr   getCodSucO;
        
	getPropertyIntPtr   getCodSucD;
        
	getPropertyIntPtr   getCodBulto;
        
	getPropertyCharPtr   getFIngreso;
        
	getPropertyCharPtr   getHIngreso;
        
	getPropertyCharPtr   getFSalida;
        
	getPropertyCharPtr   getHSalida;
        
	getPropertyCharPtr   getDetalle;

	    //-- setters
        
	setPropertyIntPtr   setCodigo;
        
	setPropertyIntPtr   setCodSucO;
        
	setPropertyIntPtr   setCodSucD;
        
	setPropertyIntPtr   setCodBulto;
        
	setPropertyCharPtr   setFIngreso;
        
	setPropertyCharPtr   setHIngreso;
        
	setPropertyCharPtr   setFSalida;
        
	setPropertyCharPtr   setHSalida;
        
	setPropertyCharPtr   setDetalle;

// getter de objeto relacionado
        getSucursalObjPtr  getSucursalObjO;
        obj_Sucursal *sucursal_o;
        getSucursalObjPtr  getSucursalObjD;
        obj_Sucursal *sucursal_d;
        getBultoObjPtr  getBultoObj;
        obj_Bulto *bulto;

	}obj_TrackViaje;
	// funcionalidad publica que se implementa en TrackViaje.c
	extern obj_TrackViaje *TrackViaje_new ();
	// meta data para acceder a las TrackViajes - definicion de las columnas de la tabla
	static Column cols_TrackViaje[CNT_COL_TRACK_VI]=
	{ 
	//definicion del mapeo, por cada columna de la tabla con los atributos del pseudobjeto.
	// nombre de la columna, tipo, tamaño, si es clave, si es autonumerado.
    
	{"codigo",t_int,sizeof(int),true,true},
    
	{"cod_suc_o",t_int,sizeof(int),false,false},
    
	{"cod_suc_d",t_int,sizeof(int),false,false},
    
	{"cod_bulto",t_int,sizeof(int),false,false},
    
	{"f_ingreso",t_varchar,(sizeof(char)*MAX10)+1,false,false},    
	{"h_ingreso",t_varchar,(sizeof(char)*MAX5)+1,false,false},    
	{"f_salida",t_varchar,(sizeof(char)*MAX10)+1,false,false},    
	{"h_salida",t_varchar,(sizeof(char)*MAX5)+1,false,false},    
	{"detalle",t_varchar,(sizeof(char)*MAX150)+1,false,false},
	};
	// plantilla para la TrackViaje.
	static Table table_TrackViaje={"track_viaje",CNT_COL_TRACK_VI,0, cols_TrackViaje,NULL};
	// generar PunteroGenerico para usar puntero funcion que obtenga pseudoObjeto TrackViaje
	typedef obj_TrackViaje *(*getTrackViajeObjPtr)(void *self);
#endif
