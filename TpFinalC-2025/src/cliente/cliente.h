#ifndef CLIENTE_INCLUDED
	#define CLIENTE_INCLUDED
	#define CNT_COL_CLIENTE 9
	#define POS_CODIGO_CLI 0
	#define POS_USUARIO_CLI 1
	#define POS_CLAVE_CLI 2
	#define POS_CUIL_CLI 3
	#define POS_RAZON_SOCIAL_CLI 4
	#define POS_DIRECCION_CLI 5
	#define POS_COD_POSTAL_CLI 6
	#define POS_EMAIL_CLI 7
	#define POS_CELULAR_CLI 8

	//----------------------------------------------------
	typedef struct {
		IOBJECT	 // crea definicion de propiedades comunes a Object .. Macro en orm.h     
	    //-- getters
        
	getPropertyIntPtr   getCodigo;
        
	getPropertyCharPtr   getUsuario;
        
	getPropertyCharPtr   getClave;
        
	getPropertyCharPtr   getCuil;
        
	getPropertyCharPtr   getRazonSocial;
        
	getPropertyCharPtr   getDireccion;
        
	getPropertyIntPtr   getCodPostal;
        
	getPropertyCharPtr   getEmail;
        
	getPropertyCharPtr   getCelular;

	    //-- setters
        
	setPropertyIntPtr   setCodigo;
        
	setPropertyCharPtr   setUsuario;
        
	setPropertyCharPtr   setClave;
        
	setPropertyCharPtr   setCuil;
        
	setPropertyCharPtr   setRazonSocial;
        
	setPropertyCharPtr   setDireccion;
        
	setPropertyIntPtr   setCodPostal;
        
	setPropertyCharPtr   setEmail;
        
	setPropertyCharPtr   setCelular;

// getter de objeto relacionado
        getLocalidadObjPtr  getLocalidadObj;
        obj_Localidad *localidad;

	}obj_Cliente;
	// funcionalidad publica que se implementa en Cliente.c
	extern obj_Cliente *Cliente_new ();
	// meta data para acceder a las Clientes - definicion de las columnas de la tabla
	static Column cols_Cliente[CNT_COL_CLIENTE]=
	{ 
	//definicion del mapeo, por cada columna de la tabla con los atributos del pseudobjeto.
	// nombre de la columna, tipo, tamaño, si es clave, si es autonumerado.
    
	{"codigo",t_int,sizeof(int),true,true},
    
	{"usuario",t_varchar,(sizeof(char)*MAX90)+1,false,false},    
	{"clave",t_varchar,(sizeof(char)*MAX120)+1,false,false},    
	{"cuil",t_varchar,(sizeof(char)*MAX20)+1,false,false},    
	{"razon_social",t_varchar,(sizeof(char)*MAX90)+1,false,false},    
	{"direccion",t_varchar,(sizeof(char)*MAX120)+1,false,false},    
	{"cod_postal",t_int,sizeof(int),false,false},
    
	{"email",t_varchar,(sizeof(char)*MAX90)+1,false,false},    
	{"celular",t_varchar,(sizeof(char)*MAX25)+1,false,false},
	};
	// plantilla para la Cliente.
	static Table table_Cliente={"cliente",CNT_COL_CLIENTE,0, cols_Cliente,NULL};
	// generar PunteroGenerico para usar puntero funcion que obtenga pseudoObjeto Cliente
	typedef obj_Cliente *(*getClienteObjPtr)(void *self);
#endif
