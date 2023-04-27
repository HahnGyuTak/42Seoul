# shell01

## ex01

```bash
id -nG $FT_USER |tr '' ',' |  tr -d '\n'

groups $FT_USER | tr ' ' ',' | tr -d '\n'
```

- groups 명령어 : 그룹에 속한 사용자 계정 확인
- -n : name, 이름 표시
- -G : group ID 표시, (-g는 하나만 나옴)
- | tr ' ' ',' : 공백을 쉼표로 교체해준다.
- | tr -d '\n' : 뒤에 자동으로 붙는 개행문자를 제거해준다.

## ex02

```bash
find . -name "*.sh" -type f -exec basename {} .sh \;
```

- find : 파일 및 디렉토리 찾는 명령어
- -name : 파일 이름 지정
- - type f : 파일만 찾기
- -exec \; : find 명령어로 찾은 결과 대상에 대하여 원하는 명령어를 적용
- basename : 파일 이름만 추출
- {} : 앞의 find의 결과값에 적용
- .sh : 출력하지 않을 확장자 입력

## ex03

```bash
find . | wc -l
```

- find : 파일 찾기
- . : 현재 및 하위 디렉토리
- | wc -l : 앞의 결과의 line 개수를 count

## ex04

```bash
ifconfig -a | grep -v ether | sed 's/ether //p' | cut -c 2-
```

- ifconfig : 네트워크 인터페이스 구성
- -a : 비활성화된 인터페이스를 볼수 있음
- egrep : grep명령어를 정규표현식으로 사용가능하게 함
- “ether “ : 정규표현식으로,  (ether ) 가 들어가는 문자열만 추출
- sed : 문자열을 편집하는 명령어
- ‘s/ether //p’ : s는 교체한다는 명령어( s/A/B/ 는 A를 B로 교체), p는 s랑 같이쓰는 명령어로써, 출력을 의미
- cut -c 2- : 앞의 공백과 tap키를 제외하고 출력(2번째부터 출력)

## ex05

```bash
echo -n 42 > "\"\?\$*'MaRViN'*\$?\\\""
```

- echo : 파일 생성 명령어
- -n 42 : 개행문자 제거한 상태에서 42 입력
- ” “, ‘ ’ : 내부에 작성된 특수문자 기능을 상실, “” 는 ‘’의 기능 상실, ‘’는 “”의 기능 상실
- \ : 특수문자 앞에서 쓰여져 해당 문자 기능 상실

## ex06

```bash
ls -l | awk 'NR%2==1'
```

- awk : 문서에서 패턴을 검사해 원하는 값을 얻음
- NR : 현재 레코드값 ( 레코드는 각 라인을 의미)
- awk 시스템 변수

<img width="802" alt="Screen_Shot_2022-05-18_at_6 08 07_PM" src="https://user-images.githubusercontent.com/50629765/234813913-960b2316-8d19-4356-af53-994a828afba8.png">

## ex07

```bash
cat /etc/passwd | sed -n '11,$p' | cut -d ':' -f1 | rev | sort -r | awk -v X=$FT_LINE1 -v Y=$FT_LINE2 'NR >= X && NR <= Y' | tr '\n' ', ' | sed 's/.$//' | sed 's/$/./g'
```

- sed -n '11,$p' : 주석부분 이후인 11번째 부터 추출
- cut -d ':' -f1 : 콜롬(:)을 기준으로 나눈 후, 가장 처음부분인 f1 부분만 추출
- rev : 각 단어를 역순으로 출력
- sort -r : 알파벳 기준 역순으로 정렬
- awk -v X=\$FT_LINE1 -v Y=\$FT_LINE2 'NR >= X && NR <= Y’: -v 옵션으로 환경변수 지정, 후 지정한 변수(X, Y)를 ‘ ‘ 안에 대입
- 환경변수 설정은 export 환경변수=값
- tr '\n' ', ' : 개행문자(\n)을 콜롬(,)으로 변경
- sed 's/.$//' | sed 's/$/./g' : 마지막에있는 문자 삭제, 마지막에 콤마 마침표 추가

## ex08

```bash
echo $FT_NBR1 + $FT_NBR2 | tr "'"'\\"?!mrdoc' '0123401234' | xargs -I{} echo "obase=13; ibase=5; {}" | bc | tr "0123456789ABC" "gtaio luSnemf"
```

- echo : 값 출력
- tr "'"'\\"?!mrdoc' '0123401234' : 각 문자를 5진수 숫자로 변환
- xargs -I  {} : xargs에 전달된 라인 전체를 뒤에 나오는 명령어의 인자로 사용
- echo "obase=13; ibase=5; {}" : 뒤에나올 bc의 변수인 obase(출력진법) ibase(입력진법)
- bc : 계산
- tr "0123456789ABC" "gtaio luSnemf" : 출력으로 나온 13진수의 숫자들을 해당된 문자로 변환
