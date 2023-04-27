# Shell00

## ex00
  
```jsx
vim z
```

## ex01

```bash
vim testShell00
```

- 개행으로 40줄 만듬
- chmod 를 이용해 권한 변경
- **touch 를 이용해 파일 타임스태프 변경**

```bash
touch -t 202106012341 testShell00 #YYYYMMDDhhmm
```

tar 압축풀기

```bash
tar -xvf testShell00.tar
```

## ex02

**권한** **하드링크수** 작성자 **파일크기 날짜 시간(혹은 연도)** 파일이름

- **볼드체**만 ****수정하면됨

## ex03

```bash
klist -l > klist.txt
혹은
klist -f > klist.txt
```

## ex04

- -p : 슬레쉬 출력
- -m : 콤마 출력
- -Ut : 생성일 기준 정렬 출력
- -ltu

```bash
ls -Utmp
```

## ex05

```bash
git log -n5 --pretty=tformat:%H
```

- -n5 : 마지막 5개 출력
- —pretty : 각 커밋 정보를 출력
- tforamt :%H : 제목을 전부 출력
  
## ex06

```bash
git ls-files --exclude-standard --ignored --others
```

- --exclude-standard : gitignore 파일의 규칙에 따른다. 즉, git ignore 에 명시된 파일은 표시하지 않는다.
- --ignored : 출력에서 무시된 파일만 표시
- --others : 출력에 다른 (즉, 추적되지 않은) 파일 표시

## ex07

```bash
patch -o b a sw.diff
```

- -o b : **b라는 파일에**
- a sw.diff : a에 sw.diff파일을 적용한 것을
- patch : 패치해서 저장하겠다

## ex08

```bash
find ./ -type f \( -name "#*#" -o -name "*~" \) -print -delete
```

- ./ : 현재, 하위 디렉토리
- type f : 파일 형식만
- \( -name "#*#" -o -name "*~" \) : -o 는 or의 의미, -name 옵션으로 제목 형식 지정
- -print : 출력하고
- -delete : 삭제

## ex09
