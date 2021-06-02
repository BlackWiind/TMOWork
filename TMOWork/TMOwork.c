#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include <locale.h>

void onestep();

double T = 10.0;  //�������� ����������
const double dt = 0.001;  //��� �������������
int summconntry = 0; //������� �����������
int summconnerr = 0; //������
bool line = false;  // ��������� ������, �.�. �� ������� ������� ���� ����� ���� ���������� ���������� ��� ��������
double u = 1.960; //�������� ����������� �������������

struct computers
{
	double connintence;  //������� ������������� �����������
	double releaseintence;  //������� ������������� �����������
	bool isConnected;  //��������� ��������� � ����

};
struct computers pcs[] = { 4.42, 49.896, false, 7.25, 14.328, false, 11.58, 29.666, false, 8.83, 45.028, false, 6.91, 22.62, false };  // �������������� ������ �� ���� �����������

int main(void) {
	setlocale(LC_ALL, "RUS");
	for (int i = 0; i < 10; i++) {
		onestep();
	}
	double p = (summconnerr * 1.0) / summconntry;
	printf("%s", "������������� �������� = ");
	printf("%5.3f", p - u * (sqrt((p * (1 - p) / summconntry))));
	printf(" , ");
	printf("%5.3f", p + u * (sqrt((p * (1 - p) / summconntry))));
	getchar();
	return EXIT_SUCCESS;
}

void onestep() {
	srand(time(NULL));
	double step = 0.001;
	int conntry = 0;
	int connerr = 0;
	while (step <= T) {
		for (int i = 0; i < 5; i++) {
			double tmp = rand() % 100 / 100.0;
			if (pcs[i].isConnected == false) {
				if (tmp <= pcs[i].connintence * step) {
					conntry++;
					if (line == false) {
						pcs[i].isConnected = true;
						line = true;
					}
					else {
						connerr++;
					}
				}
			}
			else {
				if (tmp <= pcs[i].releaseintence * step) {
					pcs[i].isConnected = false;
					line = false;
				}
			}
		}
		step = step + dt;
		summconntry = summconntry + conntry;
		summconnerr = summconnerr + connerr;
	}
}
