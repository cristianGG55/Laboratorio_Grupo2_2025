#ifndef FACTURA_INCLUDED
	#define FACTURA_INCLUDED
	#define CNT_COL_FACTURA 7
	#define POS_CODIGO_FAC 0
	#define POS_NRO_FAC 1
	#define POS_SERIE_FAC 2
	#define POS_LETRA_FAC 3
	#define POS_FECHA_FAC 4
	#define POS_COD_CLIENTE_FAC 5
	#define POS_COD_MPAGO_FAC 6

	//----------------------------------------------------
	typedef struct {
		IOBJECT	 // crea definicion de propiedades comunes a Object .. Macro en orm.h     
	    //-- getters
        
	getPropertyIntPtr   getCodigo;
        
	getPropertyIntPtr   getNro;
        
	getPropertyIntPtr   getSerie;
        
	getPropertyCharPtr   getLetra;
        
	getPropertyCharPtr   getFecha;
        
	getPropertyIntPtr   getCodCliente;
        
	getPropertyIntPtr   getCodMpago;

	    //-- setters
        
	setPropertyIntPtr   setCodigo;
        
	setPropertyIntPtr   setNro;
        
	setPropertyIntPtr   setSerie;
        
	setPropertyCharPtr   setLetra;
        
	setPropertyCharPtr   setFecha;
        
	setPropertyIntPtr   setCodCliente;
        
	setPropertyIntPtr   setCodMpago;

// getter de objeto relacionado
        getClienteObjPtr  getClienteObj;
        obj_Cliente *cliente;
        getMedioPagoObjPtr  getMedioPagoObj;
        obj_MedioPago *medio_pago;

	}obj_Factura;
	// funcionalidad publica que se implementa en Factura.c
	extern obj_Factura *Factura_new ();
	// meta data para acceder a las Facturas - definicion de las columnas de la tabla
	static Column cols_Factura[CNT_COL_FACTURA]=
	{ 
	//definicion del mapeo, por cada columna de la tabla con los atributos del pseudobjeto.
	// nombre de la columna, tipo, tamaño, si es clave, si es autonumerado.
    
	{"codigo",t_int,sizeof(int),true,true},
    
	{"nro",t_int,sizeof(int),false,false},
    
	{"serie",t_int,sizeof(int),false,false},
    
	{"letra",t_varchar,(sizeof(char)*MAX1)+1,false,false},    
	{"fecha",t_varchar,(sizeof(char)*MAX10)+1,false,false},    
	{"cod_cliente",t_int,sizeof(int),false,false},
    
	{"cod_mpago",t_int,sizeof(int),false,false},

	};
	// plantilla para la Factura.
	static Table table_Factura={"factura",CNT_COL_FACTURA,0, cols_Factura,NULL};
	// generar PunteroGenerico para usar puntero funcion que obtenga pseudoObjeto Factura
	typedef obj_Factura *(*getFacturaObjPtr)(void *self);
#endif
