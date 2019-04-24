#include <bits/stdc++.h>
//#include "mersenneTwister.h"
#define GANHA 2
#define EMPATA 1
#define PERDE 0

using namespace std;

//f1(x) = -raiz(3)/3
//f2(x) = +raiz(3)/3 

struct no{
	double id;
	string nome; 
};

//raio=1, posicao de inicio=0.5 na bissetriz da posicao
int maxMovimentos= 6;
double limite=0.9;
string time1;
string time2;
int saldoGolsTime1;
int saldoGolsTime2;
int posicaoAtualTime1;
int posicaoAtualTime2;
int rodada;
bool serieATime1, serieATime2;
int rivalidade;
int posicaoF1, posicaoF2;
vector<bool> movimentos;
vector<string> timesGrandes;
map<string, string> classico;
vector<no> arvore;
double numeroVitoriasT1, numeroVitoriasT2, golsFeitosT1, golsFeitosT2, golsContraT1, golsContraT2, saldoGolsT1, saldoGolsT2; 
double numeroVitoriasForaT1, numeroVitoriasForaT2, numeroEmpateT1, numeroEmpateT2, numeroDerrotasT1, numeroDerrotasT2;
//pos: posicaoAtual, confrontoSerieAB, posicaoFinal, saldoDeGols, rivalidade

double arvoreC(){
	no temporario;
	for(int i=0; i<35; i++){
		arvore.push_back(temporario);
	}
	arvore[0].nome="NVF_Time2";
	arvore[1].nome="NV_Time2";
	arvore[2].nome="NE_Time1";
	arvore[3].nome="ND_Time2";
	arvore[4].nome="SG_Time1";
	arvore[5].nome="GC_Time2";
	arvore[6].nome="GF_Time1";
	arvore[7].nome="SG_Time2";
	arvore[8].nome="GF_Time1";
	arvore[9].nome="ND_Time2";
	arvore[10].nome="SG_Time1";
	arvore[11].nome="GC_Time2";
	arvore[12].nome="SG_Time2";
	arvore[13].nome="NVF_Time2";
	arvore[14].nome="GC_Time1";
	arvore[15].nome="GF_Time2";
	arvore[16].nome="GF_Time1";
	arvore[17].nome="Resultado1";
	arvore[18].nome="Resultado2";
	arvore[19].nome="Resultado3";
	arvore[20].nome="Resultado4";
	arvore[21].nome="Resultado5";
	arvore[22].nome="Resultado6";
	arvore[23].nome="Resultado7";
	arvore[24].nome="Resultado8";
	arvore[25].nome="Resultado9";
	arvore[26].nome="Resultado10";
	arvore[27].nome="Resultado11";
	arvore[28].nome="Resultado12";
	arvore[29].nome="Resultado13";
	arvore[30].nome="Resultado14";
	arvore[31].nome="Resultado15";
	arvore[32].nome="Resultado16";
	arvore[33].nome="Resultado17";
	arvore[34].nome="Resultado18";
	arvore[0].id=1.5;
	arvore[1].id=16;
	arvore[2].id=0.5;
	arvore[3].id=1.5;
	arvore[4].id=5.5;
	arvore[5].id=14;
	arvore[6].id=26;
	arvore[7].id=-0.5;
	arvore[8].id=10;
	arvore[9].id=14;
	arvore[10].id=-5.5;
	arvore[11].id=12;
	arvore[12].id=-0.5;
	arvore[13].id=4.5;
	arvore[14].id=42;
	arvore[15].id=34;
	arvore[16].id=42;
	arvore[17].id=0;
	arvore[18].id=0;
	arvore[19].id=1;
	arvore[20].id=0;
	arvore[21].id=2;
	arvore[22].id=1;
	arvore[23].id=0;
	arvore[24].id=1;
	arvore[25].id=2;
	arvore[26].id=2;
	arvore[27].id=1;
	arvore[28].id=2;
	arvore[29].id=0;
	arvore[30].id=0;
	arvore[31].id=2;
	arvore[32].id=2;
	arvore[33].id=2;
	arvore[34].id=2;

	double resultadoFinal;
	if(numeroVitoriasForaT1 < arvore[0].id){
		if(numeroEmpateT2 >= arvore[2].id){
			if(saldoGolsT1 < arvore[4].id){
				if(golsFeitosT1 < arvore[6].id){
					if(golsFeitosT1 >= arvore[8].id){
						resultadoFinal=arvore[29].id;
					}else{
						if(golsContraT2 >= arvore[11].id){
							resultadoFinal=arvore[30].id;
						}else{
							resultadoFinal=arvore[31].id;
						}	
					}
				}else{
					resultadoFinal=arvore[32].id;
				}
			}else{
				resultadoFinal=arvore[33].id;
			}
		}else{
			resultadoFinal=arvore[34].id;
		}
	}else{
		if(numeroVitoriasT2 < arvore[1].id){
			if(numeroDerrotasT2 < arvore[2].id){
				resultadoFinal=arvore[17].id;
			}else{
				if(golsContraT2 >= arvore[5].id){
					if(saldoGolsT2 < arvore[7].id){
						if(numeroDerrotasT2 < arvore[9].id){
							resultadoFinal=arvore[18].id;
						}else{
							resultadoFinal=arvore[19].id;
						}
					}else{
						if(saldoGolsT1 < arvore[10].id){
							if(saldoGolsT2 >= arvore[12].id){
								if(golsContraT1 < arvore[14].id){
									resultadoFinal=arvore[20].id;
								}else{
									resultadoFinal=arvore[21].id;
								}
							}else{
								resultadoFinal=arvore[22].id;
							}
						}else{
							if(numeroVitoriasForaT2 >= arvore[13].id){
								if(golsFeitosT2 < arvore[15].id){
									resultadoFinal=arvore[23].id;
								}else{
									if(golsFeitosT1 >= arvore[16].id){
										resultadoFinal=arvore[24].id;
									}else{
										resultadoFinal=arvore[25].id;
									}
								}
							}else{
								resultadoFinal=arvore[26].id;
							}	
						}
					}
				}else {
					resultadoFinal=arvore[27].id;
				}
			}
		}else{
			resultadoFinal=arvore[28].id;
		}
	}
	return resultadoFinal;	
}

void carregarClassicos(){
	classico.insert(pair<string,string>("Flamengo","Vasco"));
	classico.insert(pair<string,string>("Vasco", "Flamengo"));
	classico.insert(pair<string,string>("Grêmio", "Internacional"));
	classico.insert(pair<string,string>("Internacional", "Grêmio"));
	classico.insert(pair<string,string>("Palmeiras", "Corinthians"));
	classico.insert(pair<string,string>("Corinthians", "Palmeiras"));
	classico.insert(pair<string,string>("Atlético-MG", "Cruzeiro"));
	classico.insert(pair<string,string>("Cruzeiro", "Atlético-MG"));
	classico.insert(pair<string,string>("Bahia", "Vitória"));
	classico.insert(pair<string,string>("Vitória", "Bahia"));
	classico.insert(pair<string,string>("Santos", "São Paulo"));
	classico.insert(pair<string,string>("São Paulo", "Santos"));
}

void carregandoVetorDeTimesGrandes(){
	timesGrandes.push_back("Internacional");
	timesGrandes.push_back("Corinthians");
	timesGrandes.push_back("Cruzeiro");
	timesGrandes.push_back("Santos");
	timesGrandes.push_back("Flamengo");
	timesGrandes.push_back("Atlético-MG");
	timesGrandes.push_back("Grêmio");
	timesGrandes.push_back("São Paulo");
	timesGrandes.push_back("Fluminense");
	timesGrandes.push_back("Palmeiras");
}

bool teste(double *posicaoX, double *posicaoY){
	bool teste=0;
	double px = (*posicaoX)*(*posicaoX);
	double py = (*posicaoY)*(*posicaoY);
	double total = px+py;
	if(total>=limite){
		teste=1;
	}
	return teste;
}

void posicaoAtual(double *posicaoX, double *posicaoY){
	double mudanca;
	mudanca = (posicaoAtualTime1-posicaoAtualTime2)/38;
	if(mudanca <= 0){
		mudanca = abs(mudanca);
		(*posicaoX) = (*posicaoX)+((2*mudanca)/3);
		(*posicaoY) = (*posicaoY)+((1*mudanca)/3);
	}else{
		(*posicaoX) = (*posicaoX)-((1*mudanca)/3);
		(*posicaoY) = (*posicaoY)-((2*mudanca)/3);
	}
}

void confrontoSerieAB(double *posicaoX, double *posicaoY){
	if((serieATime1==1 && serieATime2==0) || (serieATime1==0 && serieATime2==1)){
		if(serieATime1){
			(*posicaoX)+=0.1;
			(*posicaoY)+=0.1;
		}else{
			(*posicaoX)-=0.1;
			(*posicaoY)-=0.1;
		}
	}
}

void saldoGols(double *posicaoX, double *posicaoY){
	double saldoGols=0;
	if(saldoGolsTime1<0 && saldoGolsTime2<0){
		saldoGols = saldoGolsTime1-saldoGolsTime2;
		saldoGols/=35;
		if(saldoGols>0){
			(*posicaoX) = (*posicaoX)+((2*saldoGols)/3);
			(*posicaoY) = (*posicaoY)+((1*saldoGols)/3);	
		}else if(saldoGols<0){
			(*posicaoX) = (*posicaoX)+((1*saldoGols)/3);
			(*posicaoY) = (*posicaoY)+((2*saldoGols)/3);
		}
	}
}

void rivalidadeEspaco(double *posicaoX, double *posicaoY){
	if(classico[time1] == "time2" && abs(posicaoAtualTime1-posicaoAtualTime2)>= 4 ){
		double px = rand() % 11 ;
		double py = rand() % 11;
		int aleatoriedade = rand() % 10;
		if(aleatoriedade<=4){
			px-=2*px;
		}
		aleatoriedade = rand() % 10;
		if(aleatoriedade<=4){
			py-=2*py;
		}
		px/=30;
		py/=30;
		(*posicaoX)+=px;
		(*posicaoY)+=py;
	}
}

void timeGrandeMud(double *px, double *py){
	for(int i=0; i<timesGrandes.size(); i++){
		if(timesGrandes[i] == "time1"){
			(*px)+=0.1;
			(*px)+=0.1;
			break;
		}
	}
	for(int i=0; i<timesGrandes.size(); i++){
		if(timesGrandes[i] == "time2"){
			(*px)-=0.1;
			(*px)-=0.1;
			break;
		}
	}
}

void mudPelaPosicaoFinal(double *px, double *py){
	if(posicaoF1-posicaoF2 < 0 && rodada < 2){
		(*px)+=0.05*abs(posicaoF1-posicaoF2-(rand() % 3));
		(*py)+=0.05*abs(posicaoF1-posicaoF2-(rand() % 3));
	}else{
		(*px)-=0.05*abs(posicaoF1-posicaoF2 +(rand() % 3));
		(*py)-=0.05*abs(posicaoF1-posicaoF2+(rand() % 3));
	}
	if(posicaoF1-posicaoF2 < 0 && rodada >= 3){
		(*px)+=0.05*abs(posicaoF1-posicaoF2-(rand() % 1));
		(*py)+=0.05*abs(posicaoF1-posicaoF2-(rand() % 1));
	}else{
		(*px)-=0.05*abs(posicaoF1-posicaoF2 +(rand() % 1));
		(*py)-=0.05*abs(posicaoF1-posicaoF2+(rand() % 1));
	}
}

void vizinhanca(int decisao, double *posicaoX, double *posicaoY){
	int movimentacao = 0;
	bool atingiuObjetivo=0;
	while(movimentacao<maxMovimentos && !atingiuObjetivo){
		if(movimentos[movimentacao]){
			switch (movimentacao){
				case 0:
					posicaoAtual(posicaoX, posicaoY);
					break;
				case 1: 
					confrontoSerieAB(posicaoX, posicaoY);
					break;
				case 2: 
					saldoGols(posicaoX, posicaoY);
					break;
				case 3:
					rivalidadeEspaco(posicaoX, posicaoY);
					break;
				case 4:
					timeGrandeMud(posicaoX, posicaoY);
					break;
				case 5:
					mudPelaPosicaoFinal(posicaoX, posicaoY);
					break;
			}
			movimentos[movimentacao]=0;
		}
		atingiuObjetivo = teste(posicaoX, posicaoY);
		if(atingiuObjetivo){
			return;
		}
		movimentacao++;
	}	
}

void marcarTimesSerieA(){
	if(time1=="América-MG" || time1=="Internacional" || time1=="Ceará SC" || time1=="Paraná"){
		serieATime1=0;
	}else{
		serieATime1=1;
	}
	
	if(time2=="América-MG" || time2=="Internacional" || time2=="Ceará SC" || time2=="Paraná"){
		serieATime2=0;
	}else{
		serieATime2=1;
	}
}

void posicaoInicial(double *x, double *y, int decisao){
	if(rodada < 7){
		if(decisao == 0){
			(*x) = -0.1;
			(*y) = 0.1*(sqrt(3)/3);
		}else if(decisao == 1){
			(*x) = 0.0;
			(*y) = -0.1;
		}else{
			(*x) = 0.1;
			(*y) = 0.1*(sqrt(3)/3);
		}
	}else{
		if(decisao == 0){
			(*x) = -0.5;
			(*y) = 0.5*(sqrt(3)/3);
		}else if(decisao == 1){
			(*x) = 0.0;
			(*y) = -0.5;
		}else{
			(*x) = 0.5;
			(*y) = 0.5*(sqrt(3)/3);
		}
	}
}

int carregarPosicaoFinal(string timeP){
	int posicao=0;
	if(timeP == "Flamengo")
		posicao=6;
	if(timeP == "Atlético")
		posicao=9;
	if(timeP == "São Paulo")
		posicao=13;
	if(timeP == "Internacional")
		posicao=2;
	if(timeP == "Grêmio")
		posicao=4;
	if(timeP == "Palmeiras")
		posicao=2;
	if(timeP == "Sport")
		posicao=15;
	if(timeP == "Cruzeiro")
		posicao=5;
	if(timeP == "Botafogo")
		posicao=10;
	if(timeP == "Corinthians")
		posicao=1;
	if(timeP == "Vasco")
		posicao=7;
	if(timeP == "Fluminense")
		posicao=14;
	if(timeP == "Ámerica-MG")
		posicao=1;
	if(timeP == "Chapecoense")
		posicao=8;
	if(timeP =="Santos")
		posicao=3;
	if(timeP == "Vitória")
		posicao=16;
	if(timeP == "Bahia")
		posicao=12;
	if(timeP == "Paraná")
		posicao=4;
	if(timeP == "Atlético-PR")
		posicao=11;
	if(timeP =="Ceará")
		posicao=3;
	return posicao;
}

int posicao(double *px, double *py){
	if((*px)>0 && (*py)>0){
		return 2;
	}else if((*px)<0 && (*py)<0){
		return 0;
	}else if((*px)>0 && (*py)<=0){
		double auxi = (*px)*(-(sqrt(3)/3));
		if((*py)<=auxi){
			return 1;
		}else{
			return 2;
		} 
	}else if((*px)<0 && (*py)<=0){
		double auxi = (*px)*(sqrt(3)/3);
		if((*py)<=auxi){
			return 1;
		}else{
			return 0;
		}
	}else if((*px)==0 && (*py)==0){
		return 0;
	}else if((*px)==0 && (*py)<0){
		return 1;
	}
	return 1;
}

int main(){
	//passsar dados de entrada
	srand(1);
	int decisao=0;
	bool auxiliar=1;
	for(int i=0; i<maxMovimentos; i++){
		movimentos.push_back(auxiliar);
	}
	cout<<"Digite o time 1\n";
	getline(cin, time1);
	cout<<"Digite o time 2\n";
	getline(cin, time2);
	
	cout<<"Digite o saldo de gols de "<<time1<<endl;
	cin>>saldoGolsT1;
	cout<<"Digite o saldo de gols de "<<time2<<endl;
	cin>>saldoGolsT2;
	
	cout<<"Digite a posicao de "<<time1<<endl;
	cin>>posicaoAtualTime1;
	cout<<"Digite a posicao de "<<time2<<endl;
	cin>>posicaoAtualTime2;
	
	cout<<"Digite o numero de vitorias de "<<time1<<endl;
	cin>>numeroVitoriasT1;
	cout<<"Digite o numero de vitorias de "<<time2<<endl;
	cin>>numeroVitoriasT2;
	
	cout<<"Digite o numero de vitorias fora de "<<time1<<endl;
	cin>>numeroVitoriasForaT1;
	cout<<"Digite o numero de vitorias fora de "<<time2<<endl;
	cin>>numeroVitoriasForaT2;
	
	cout<<"Digite o numero de gols feitos por "<<time1<<endl;
	cin>>golsFeitosT1;
	cout<<"Digite o numero de gols feitos por "<<time2<<endl;
	cin>>golsFeitosT2;
	
	cout<<"Digite o numero de gols sofridos por "<<time1<<endl;
	cin>>golsContraT1;
	cout<<"Digite o numero de gols sofridos por "<<time2<<endl;
	cin>>golsContraT2;
	
	cout<<"Digite o numero de empates de "<<time1<<endl;
	cin>>numeroEmpateT1;
	cout<<"Digite o numero de emaptes "<<time2<<endl;
	cin>>numeroEmpateT2;	
	
	cout<<"Digite o numero de derrotas de "<<time1<<endl;
	cin>>numeroDerrotasT1;
	cout<<"Digite o numero de derrotas de "<<time2<<endl;
	cin>>numeroDerrotasT2;	
	
	cout<<"Digite a rodada\n";
	cin>>rodada;
	
	saldoGolsTime1 = (int) saldoGolsT1; 
	saldoGolsTime2 = (int) saldoGolsT2;
		
	decisao = (int) arvoreC();
	carregarClassicos();
	carregandoVetorDeTimesGrandes();
	carregarClassicos();
	marcarTimesSerieA();
	posicaoF1 = carregarPosicaoFinal(time1);
	posicaoF2 = carregarPosicaoFinal(time2);
	double pX, pY;
	posicaoInicial(&pX, &pY, decisao);
	vizinhanca(decisao, &pX, &pY);
	decisao = posicao(&pX, &pY);
	cout<<"Resultado foi ";
	if(decisao == 0){
		cout<<"Vitoria do "<<time2<<endl;
	}else if(decisao == 1){
		cout<<"Empate\n";
		
	}else{
		cout<<"Vitoria do "<<time1<<endl;
	}
}


