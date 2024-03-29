# Smartwatch
É um relógio inteligente para micro controlador ATMEGA328P e display gráfico Nokia 5110.

#### Características:
- Data/Hora
<img src="https://raw.githubusercontent.com/rnrdias/smartwatch/master/docs/images/dpy0001.png"/>
- Alarme - Hora - Dia da semana
<img src="https://raw.githubusercontent.com/rnrdias/smartwatch/master/docs/images/dpy0004.png"/>
- Cronometro - Start,Stop e step
<img src="https://raw.githubusercontent.com/rnrdias/smartwatch/master/docs/images/dpy0008.png"/>
- Calendário
<img src="https://raw.githubusercontent.com/rnrdias/smartwatch/master/docs/images/dpy0006.png"/>

#### Motor gráfico:
- Lista
<img src="https://raw.githubusercontent.com/rnrdias/smartwatch/master/docs/images/dpy0007.png"/>
- Definir valor
<img src="https://raw.githubusercontent.com/rnrdias/smartwatch/master/docs/images/dpy0009.gif"/>
- Definir valor sobre a lista
<img src="https://raw.githubusercontent.com/rnrdias/smartwatch/master/docs/images/dpy0010.gif"/>

#### Estrutura de pastas do projeto
- electric: contem os esquemas elétrico e o layout
- docs: informações gerais e datasheets
- mechanic: projeto mecânico, posicionamento dos componentes
- firmware: contem o código fonte do smartwatch, compilação para AVR ou PC(simulador).


#### Detalhes do firmware:
+ app: aplicações executadas em segundo plano
+ build: binários gerados
+ kernel: núcleo do sistema
   + drivers: contem as interfaces e implementações dos hardwares
        + simulador: drivers para o simulador
        + atmega328p: drivers para o atmega328p
   + fonts: armazenamento de fontes
   + screen: telas do sistema
   + settings: definição das configurações e ligação das funções
   + upp: definição de funções para manipulação de gráficos baixo nível
+ language: definição dos idiomas
+ screens: telas para usuário final


#### Compilação:
Para o simulador:
```sh
$ make all_simulator
```
Para o avr:
```sh
$ make all_avr
```
Para recompilação (remove os arquivos binários e objetos):
```sh
$ make clean
```


#### Para o futuro:
+ integração com sistema Android, Bluetooth
    + sincronização das notificações
    + sincronização do calendário
    + identificação de ligações o número de telefone
+ controle de eletrodomésticos por infravermelho
+ contador de passos


### Licença
Copyright (c) 2015-2019 Ranieri Dias 
Todos os direitos reservados
Este arquivo é parte de Smartwatch.

O Smartwatch é um software livre: você pode redistribuí-lo e / ou modificar
sob os termos da Licença Pública Geral GNU, publicada pela
Free Software Foundation, versão 3 da Licença ou
(a seu critério) qualquer versão posterior.
O Smartwatch é distribuído na esperança de que seja útil,
mas SEM QUALQUER GARANTIA; sem sequer a garantia implícita de
COMERCIALIZAÇÃO ou ADEQUAÇÃO PARA UMA FINALIDADE ESPECÍFICA. Veja o
GNU General Public License para mais detalhes.
Você deveria ter recebido uma cópia da Licença Pública Geral GNU
junto com o Smartwatch. Caso contrário, consulte http://www.gnu.org/licenses/.
