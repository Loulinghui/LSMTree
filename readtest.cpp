#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>

using namespace std;

typedef struct info {
	double a;
	double b;
	double c;
}INFO;

int main(void) {

	FILE* fp = fopen("input.txt", "r");
	INFO* test = new INFO[50];
	INFO* result = new INFO[50];

	for (int i = 0; i < 50; i++) {
		fscanf(fp, "%lf %lf %lf", &test[i].a, &test[i].b, &test[i].c);
	}

	cout << test[0].a << " " << test[0].b << " " << test[0].c << endl;

	FILE* fp2 = fopen("input.bin", "wb");

	for (int i = 0; i < 50; i++) {
		fwrite(&test[i].a, sizeof(double), 1, fp2);
		fwrite(&test[i].b, sizeof(double), 1, fp2);
		fwrite(&test[i].c, sizeof(double), 1, fp2);
	}
	fclose(fp);
	fclose(fp2);

	FILE* fp3 = fopen("input.bin", "rb");

	for (int i = 0; i < 50; i++) {
		fread(&result[i].a, sizeof(double), 1, fp3);
		fread(&result[i].b, sizeof(double), 1, fp3);
		fread(&result[i].c, sizeof(double), 1, fp3);
	}

	cout << result[0].a << " " << result[0].b << " " << result[0].c << endl;

	return 0;
}
