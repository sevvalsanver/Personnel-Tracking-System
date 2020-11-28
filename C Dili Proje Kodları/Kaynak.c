#include <stdio.h>
#include <time.h>
#include <stdlib.h>




char isim[100], soyisim[200], tc[110], sifre[40], secim;


void Bilgiler()

{
	printf("Lutfen TC kimlik numaranizi giriniz:\n");
	scanf("%s", tc);
	printf("Lutfen sifrenizi giriniz:\n");

}



int main() {
	int cevap;
	char gorev1[100];
	char gorev2[100];
	char gorev3[100];
	int j;

	printf("Hangi girisi secmek istiyorsunuz? (Yonetici icin '1'i, personel icin '0'i tuslayiniz)\n ");
	printf("Yonetici girisi secerseniz kayitli personel bilgisi silinecektir!!!");
	scanf("%d", &cevap);

	if (cevap == 1)
	{
		FILE* fp = fopen("deneme.txt", "w");
		printf("Lutfen yeni kayit yapmak istediginiz personelin bilgilerini giriniz\n");
		for (j = 0; j < 5; j++) {
			printf("Yeni personelin TC kimlik numarasini giriniz:\n");
			scanf("%s", &tc);
			printf("Yeni personelin sifresini giriniz:\n ");
			scanf("%s", &sifre);
			printf("Yeni personelin gorevlerini giriniz:\n");
			scanf("%s", &gorev1);
			scanf("%s", &gorev2);
			scanf("%s", &gorev3);
			fprintf(fp, "%s", tc);
			fprintf(fp, " %s\n", sifre);
			fprintf(fp, "%s", gorev1);
			fprintf(fp, " %s", gorev2);
			fprintf(fp, " %s\n", gorev3);
		}

		fclose(fp);
	}


	else if (cevap == 0)
	{
		Bilgiler();
		// Su anki tarihi al ve formatla
		char tarih[20];
		time_t zaman;
		struct tm* zamanBilgisi;
		time(&zaman);
		zamanBilgisi = localtime(&zaman);
		strftime(tarih, sizeof(tarih), "%d.%m.%y %H:%M", zamanBilgisi);

		FILE* fp = fopen("deneme.txt", "r");
		fscanf(fp, "%s", sifre);
		char gsifre[40];
		scanf("%s", gsifre);
		printf("Yapmak istediginiz islemi seciniz: (Giris icin [G] / [g],Cikis icin [C] / [c]) \n");
		scanf(" %c", &secim);


		int i;

		fclose(fp);
		fp = fopen("deneme.txt", "r");
		char temp[100];

		if (secim == 'G' || secim == 'g')
		{
			for (i = 0; i <= 24; i++)
			{
				fscanf(fp, "%s", temp);
				if (i % 5 == 1)
				{
					if (strcmp(gsifre, temp) == 0)
					{
						printf("\nHOSGELDINIZ! Girdiginiz veriler bilgilerinizle eslesmistir.\n");
						printf("Giris yaptiginiz zaman: %s\n\n", tarih);
						fscanf(fp, "%s", gorev1); i++; printf("Gorevleriniz:\n%s\n", gorev1);
						fscanf(fp, "%s", gorev2); i++; printf("%s\n", gorev2);
						fscanf(fp, "%s", gorev3); i++; printf("%s\n", gorev3);
						break;
					}
					else
						printf("Lutfen sifrenizi kontrol ediniz!");


				}

			}


			fclose(fp);


			fp = fopen("deneme.txt", "a");

			fprintf(fp, "\n%s TC kimlik numarasina sahip personelin giris yaptigi tarih:%s", tc, tarih);
			fclose(fp);
		}

		if (secim == 'c' || secim == 'C')
		{
			for (i = 0; i <= 24; i++)
			{
				fscanf(fp, "%s", temp);
				if (i % 5 == 1)
				{

					if (strcmp(gsifre, temp) == 0)
					{
						printf("\nHOSGELDINIZ! Girdiginiz veriler bilgilerinizle eslesmistir.\n");
						printf("Cikis yaptiginiz zaman: %s\n\n", tarih);
						break;
					}
					else
						printf("Lutfen sifrenizi kontrol ediniz!");

				}


			}

			fclose(fp);


			fp = fopen("deneme.txt", "a");

			fprintf(fp, "\n%s TC kimlik numarasina sahip personelin cikis yaptigi tarih:%s", tc, tarih);
			printf("Giris ve cikis saatlerinize gore calisma ucretiniz maasiniza yansitilacaktir.\n Iyi Calismalar...");
			fclose(fp);

		}
	}
	return 0;
}