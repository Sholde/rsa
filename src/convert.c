#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>

#include "structure.h"
#include "convert.h"

msg *char_to_msg(char *chaine) {
	int len_chaine = strlen(chaine);
	msg *m = malloc(sizeof(msg));
	
	mpz_init_set_ui(m->size, 8 * len_chaine);
	mpz_init(m->text);
	
	for(int i = 0 ; i < len_chaine ; i++) {
		mpz_mul_2exp(m->text, m->text, 8);
		mpz_add_ui(m->text, m->text, chaine[i]);
	}
	return m;
}

char *msg_to_char(msg *m) {
	mpz_t mpz_size;
	mpz_init(mpz_size);
	mpz_div_ui(mpz_size, m->size, 8);

	int size = mpz_get_ui(mpz_size);
	char * ret = malloc(sizeof(char) * ( size + 1 ) );
	ret[size] = '\0';

	mpz_t tmp;
	mpz_init(tmp);

	mpz_t AND;
	mpz_init(AND);

	mpz_set_ui(AND, 255);

	int max = mpz_get_ui(m->size);

	for(int i = size - 1 ; i >= 0 ; i--) {
		mpz_set(tmp, m->text);
		mpz_div_2exp(tmp, tmp, max - (i + 1 ) * 8 );
		mpz_and(tmp, tmp, AND);
		ret[i] = mpz_get_ui(tmp);
	}

	return ret;
}

msg *hexa_to_msg(char *chaine) {
	//A revoir 
	int len_chaine = strlen(chaine);

	msg *m = malloc(sizeof(msg));
	mpz_init(m->text);
	mpz_init(m->size);

	mpz_set_ui(m->size, 4);
	mpz_mul_ui(m->size, m->size, len_chaine);

	for (int i = 0; i < len_chaine; i++)
	{
		int tmp = chaine[i];
		if(tmp >= 48 && tmp <= 57) {
			tmp -= 48;
		}
		else if (tmp >= 97 && tmp <= 102) {
			tmp -= (97 - 10);
		}
		else {
			exit(666);
		}
		mpz_mul_2exp(m->text, m->text, 4);
		mpz_add_ui(m->text, m->text, tmp);
	}
	
	return m;
}

char *msg_to_hexa(msg *m) {
	
	mpz_t mpz_size;
	mpz_init(mpz_size);
	mpz_div_ui(mpz_size, m->size, 4);

	int size = mpz_get_ui(mpz_size);

	char *chaine = malloc(sizeof(char) * (size + 1) );
	chaine[size] = '\0';

	mpz_t mpz_char;
	mpz_init(mpz_char);

	mpz_t AND;
	mpz_init(AND);
	mpz_set_ui(AND, 15);

	for (int i = 0; i < size; i++)
	{
		mpz_tdiv_q_2exp(mpz_char, m->text, (size - (i+1)) * 4);
		mpz_and(mpz_char, mpz_char, AND);
		char tmp = mpz_get_ui(mpz_char);
		if(tmp > 15 || tmp < 0) {
			exit(666);
		}
		if(tmp < 10) {
			tmp += 48;
		}
		else {
			tmp += 87;
		}
		chaine[i] = tmp;
	}
	
	return chaine;
}