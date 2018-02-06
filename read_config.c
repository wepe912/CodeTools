#include "./read_config.h"

int read_config(const char* path){
	FILE *fd = NULL;
	int i = 0;
	char buff[1024] = {'\0'};
	char* cc = NULL;
	char* ca = NULL;

	fd = fopen(path,"r");
	if(fd == NULL){
		return OPENFAIL;
	}
   	while(fgets(buff,1024,fd)){
		if(strchr(buff,'#'))
			continue;
		
		/* Remove trailing space */
		for (i = strlen(buff);
		     i > 0 && isascii((unsigned char)buff[i - 1]) && isspace((unsigned char)buff[i - 1]);
			)
			buff[--i] = '\0';
		/* Remove leading space */
		for (cc = buff; *cc && isascii((unsigned char)*cc) && isspace((unsigned char)*cc); cc++)
			continue;

		/* Stop if nothing left */
		if (!*cc)
			continue;

		/* Uppercase the command and find the arg */
		for (ca = cc; *ca; ca++) {
			if (isascii((unsigned char)*ca)) {
				//配置项固定为大写
				//if (islower((unsigned char)*ca)) {
				//	*ca = toupper((unsigned char)*ca);
				//} 
				 if (isspace((unsigned char)*ca) || (*ca == '='))
					break;
			}
		}

		/* Remove space (and possible =) leading the arg */
		for (; *ca && isascii((unsigned char)*ca) && (isspace((unsigned char)*ca) || (*ca == '=')); ca++)
			continue;


		/**code here to get what you want from config file**/
		if (!strncmp(cc, "statue", (size_t) 6) || !strncmp(cc, "SHMEM", (size_t) 5)) {
			char valu_str[1024] = {'\0'};
			memcpy(valu_str,ca,strlen(ca));
			printf("get the valu_str =%s\n",valu_str );
			continue;
		}
		/*****************************/

	}
	fclose(fd);
}
