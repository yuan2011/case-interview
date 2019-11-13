#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <errno.h>

struct conf{
	char test_ip[32];
	char browser[256];
	char language[32];
};

int get_value_form_line( char* key, char* value, char*line)
{
	char *tmp;
	int len=0;

	if(tmp = strstr( line, key)){
		tmp = tmp+sizeof(key)-1+3;
		len = strlen(tmp)-3;
		strncpy(value, tmp, len);
		return 0;
	}
	return -1;
}

int parse(const char *path, struct conf* conf)
{
	FILE * fp;
	char line[1024];

	fp = fopen(path, "r");
	if(!fp){
		printf("open %s:%s\n", path, strerror(errno));
		return -1;
	}

	while (fgets(line, 1023, fp) != NULL)
	{
		get_value_form_line( "test_ip", conf->test_ip, line);
		get_value_form_line( "browser", conf->browser, line);
		get_value_form_line( "language", conf->language, line);
	}

	fclose(fp);

	return 0;
}

int main(int argc, char *argv[])
{
	int ret = -1;
	struct conf conf = {0};

	if(argc < 2){
		printf("usage: ./a.out <config_file>\n");
		return -1;
	}

	ret = parse(argv[1], &conf);
	if(ret)
		printf("%s parse error\n", argv[1]);

	printf("%s %s %s..\n", conf.test_ip, conf.browser, conf.language);

	return 0;
}
