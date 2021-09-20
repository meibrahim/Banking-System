#ifndef ENUMERATIONS_H_
#define ENUMERATIONS_H_

typedef enum Roles {
    BRD_DIRECTOR  = 0,
    CEO			  = 1,
    PRSDNT        = 2,
    MNGR          = 3,
    ASSCATE       = 4,
    ACCNTS        = 5,
    CASHRS        = 6,
    CLNTS         = 7,
    INVSTRS       = 8,
    PEOPLE        = 9,
    SENIORPTR     = 10,
    JUNIORPTR     = 11
} Role_t;


typedef enum Activities {

    LOANS  		= 0,
    VOTING 		= 1,
    INVSTMNTS 	= 2,
    LOTTRY   	= 3,
    BBFNDING  	= 4,
    CUSTM_ACTY  = 5
} Activity_t;


typedef enum Banks {

    CORPORATE_BANKS  = 0,
    PRIVATE_BANKS    = 1,
    GOVERNMENT_BANKS = 2
} Banks_t;

#endif //ENUMERATIONS_H_