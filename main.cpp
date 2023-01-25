#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>

typedef void (*PFunc)(int);

void callback(int num) {
	//—”ˆ—
	srand(time(nullptr));
	int	dice = rand() % 6 + 1;

	//”»’è
	if (dice % 2 == num){
		printf("%d‚Å³‰ğ\n", dice);
	}else{
		printf("%d‚Å•s³‰ğ\n", dice);
	}
}

void	setTimeout(PFunc p, int answer, int second) {
	printf("Œ‹‰Ê‚Í\n");
	Sleep(second * 1000);

	p(answer);
}

int main(){
	int answer;

	while (true)
	{
		printf("‹ô”‚¾‚Æv‚¤‚È‚ç0AŠï”‚È‚ç1‚ğ“ü—Í\n");

		scanf_s("%d", &answer);
		if (answer == 0 || answer == 1){
			break;

		}else{
			printf("0‚Ü‚½‚Í1‚ğ“ü—Í\n");

		}
	}

	PFunc p = callback;

	setTimeout(p, answer, 3);

	system("pause");

	return 0;

}