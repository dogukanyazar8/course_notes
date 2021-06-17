/*

Ders24

Binary Search Algoritması: Burada içinde arama yapacağımız dizi belirli bir sıralama kriterine göre sıralanmış.

Linear Search Algoritması: Sıralı olmayan bir veri yapısında bir veri aramak. Dizinin bütün elemanlarına tek tek bakmak demek.


6  35  35  37  40  41  82  84 101 106 118 141 145 153 169 190 253 264 281 288 292 299 308 316 322 323 333 334 350 358 
370 376 382 391 393 421 436 439 446 447 464 467 478 491 500 529 537 538 538 541 547 548 604 623 626 629 644 648 662 664 
667 673 703 705 711 716 718 723 724 726 729 741 756 757 771 778 805 811 827 827 840 842 859 868 869 890 894 895 902 912 
929 931 942 942 944 954 961 962 966 995

Elimizde sıralı bir dizi var ve bu dizide bir değer arıyoruz. Örneğin 777 değerini arıyoruz.
Arama algoritması linear search olsaydı, dizinin ilk elemanından başlayarak son elemanına kadar tek tek kontrol edecektik 777 mi değil mi diye.

Ama buna gerek çünkü bu dizi zaten sıralı. Bu dizinin tam ortasındaki elemana baksak, dizinin tam ortasındaki değer 541 olsun, şimdi 3 ihtimal var.

Bu değer;

ya aradığım değerden küçük
ya aradığım değerden büyük
ya da aradığım değerin kendisi

Aradığımız değer 777. Bundan dolayı 541 değerinden önceki tüm değerleri ortadan kaldırabiliriz.
Yine kalan dizinin ortasına bakıyoruz. Aradığım değerden küçük mü büyük mü diye. Küçükse kalan kısmı ortadan kaldırabiliriz.
Bu şekilde aradığımız değeri, sürekli dizinin eleman sayısının yarısını elimine ederek bulabiliriz.

Böylece aramayı 1000 elemanlı bir dizide yaparken, eleman sayısı 2 katına çıksa, bir sorgulama daha yapmamız gerekir. Bu da logaritmik karmaşıklık. O(logn)

Şuan elimizdeki dizinin 100 elemanı var, bu diziyi sürekli 2'ye böleceğiz. Bunun için de üstünde çalışacağımız lojik dizinin en küçük ve en yüksek indeksini tutmamız yeterli olur.
Bu indeksler aralığını bir dizi olarak kullanacağız. Bunun için 3 tane değişekene ihtiyacımız var.

    int idx_first = 0;          -> Üstünde çalıştığım dizinin en küçük indeksi (ilk eleman indeksi)
    int idx_last = SIZE - 1;    -> Üstünde çalıştığım dizinin en büyük indeksi (son eleman indeksi)
    int idx_mid;                -> Üstünde çalıştığım dizinin ortasındaki değer

----

#include <stdio.h>
#include "dutility.h"

#define SIZE 100000

int main()
{
    int a[SIZE];
    int sval;
    int cnt = 0;

    set_random_array(a, SIZE);
    sort_array(a, SIZE);
    //print_array(a, SIZE);

    printf("Aranan degeri giriniz: ");
    scanf("%d", &sval);
    int idx_first = 0;
    int idx_last = SIZE - 1;
    int idx_mid;

    while (idx_first <= idx_last) {
        ++cnt;
        idx_mid = (idx_first + idx_last) / 2;
        if (a[idx_mid] == sval)
            break;
        
        if(a[idx_mid] > sval)
            idx_last = idx_mid - 1;
        else
            idx_first = idx_mid + 1;
    }

    if (idx_first <= idx_last) {
        printf("Aranan deger bulundu! Dizinin %d indisli elemani. Yapilan toplam sorgulama = %d\n", idx_mid, cnt);
    }
    else {
        printf("Aranan deger bulunamadi! Yapilan toplam sorgulama = %d\n", cnt);
    }
}

----

100 elemanlı bir dizide 2^7 = 128 (Toplam 7 sorgu)
1000 elemanlı bir dizide 2^10 = 128 (Toplam 10 sorgu)
50000 elemanlı bir dizide 2^16 = 128 (Toplam 16 sorgu)

----

ÖDEV

Sorunun test kodu:

#include <stdio.h>
#include <stdlib.h>
#include "dutility.h"

#define SIZE 20

int main()
{
    int a[SIZE];

    randomize();

    for (int i = 0; i < SIZE; ++i){
        a[i] = rand() % 30 + 1;
    }
}

----

Soru 1: 

1. satıra dizinin ilk elemanının değeri kadar * karakteri.
2. satıra dizinin ikinci elemanının değeri kadar * karakteri.
Böyle devam edecek dizinin son elemanına kadar.

-----

#include <stdio.h>
#include <stdlib.h>
#include "dutility.h"

#define SIZE 10

int main()
{
    int a[SIZE];

    randomize();

    for (int i = 0; i < SIZE; ++i){
        a[i] = rand() % 30 + 1;
    }

    print_array(a, SIZE);
    putline();

    for (int i = 0; i < SIZE; ++i){
        for (int j = 0; j < a[i]; ++j) {
            printf("*");
        }
        printf("\n");
    }
}

-----


Soru 2:

Örnek dizimizin elemanları: 13   8  18   1  24  20  11  18  22   8

*************
********
******************
*
************************
********************
***********
******************
**********************
********

Bu histogramı dikey olarak yazdırmamız gerekiyor. Herhangi bir ek kütüphane kullanmadan.

https://github.com/necatiergin/c_kursu_odevleri/blob/master/resimler/histogram.JPG

----------------------------------------------

Yazılar ve Char türünden diziler

C dilinin alternatif bir çok programlama diline göre genel olarak orta seviyeli dil diyoruz. Aşağısı düşük seviyeli diller, assembly diller ve makine dili.
Fakat C dilinin assembly ile mesafesi çok yakın.

Portable assembly terimi kullanılıyor C programlama dili için. Java C# gibi dillerle karşılaştırdığımızda, C'nin bu düşük seviyeli olmasının programcı üzerinde bir yükü var. 
Araçları da alt seviye. Yazı işlemleri da böyle.

Diğer dillerde string diye bir tür var. Bu dillerde aşağıdaki gibi bir kod yazabiliyoruz.

string s = "Dogukan";

Hatta C++ gibi dillerde bu ifadeleri operatörlerin operandları yapabiliyoruz.

s += "Yazar";

if (s == "Soner")

Fakat C dilinde böyle değil. C'de yazılar çok alt seviyede tutuluyor. 

Bu string türünden buradaki karşılığı elemanlarının türü char olan diziler.

char str[100];      -> Bu bir yazı tutacak dizi.

Yazı karakterlerden oluşuyor. Mesela BABA yazısı. 4 karakteri var. Her bir karakterin ASCII kodlamasında bir kodu var. B = 66 A = 65 B = 66 A = 65

Bu dizinin ilk elemanında B'nin kodunu, ikinci elemanına A'nın kodunu tutabiliyoruz. Yazı böyle tutuluyor.

Ama, diyelim bir yazı kodumuz var, kodumuzun da bu yazıyı kullanması gerekiyor.
Bir döngüyle bu dizinin elemanlarına erişilicek ve dizinin elemanlarından bu yazının karakterlerini çekicek.
Peki yazının uzunluğunu nasıl bilecek?

İşte programlama dillerinde yazılar implemente edildiği zaman iki farklı yaklaşım var.

C++ Java C# gibi yüksek seviyeli dillerde, yazının uzunluğunu, bizim doğrudan erişimize kapatılmış bir değişkende tutmak.
Yazıyı bir dizi tutuyor aslında ama yazının uzunluğunu da bir tam sayı değişken tutuyor.
Bu yazıyı işleyen kodlar, yani yazının uzunluğu soran kodlar, o tam sayı değişkeninin değeri kadar dönüyorlar.

Fakat C'de yaklaşım böyle değil. Daha alt seviye bir yaklaşım var.
C'de ise, yazının son karakterinden sonraki dizinin elemanı özel bir tam sayı değerinde olacak, böylece o diziyi dolaşan kod veya döngü, o özel değerle karşılaştığında dizinin bittiğini anlayacak.

Kısacası yazının son karakterinden sonra özel bir karakter kodluyoruz. Yazının sonunu belirleyen özel karaktere null character deniliyor. Sonlandırıcı karakter.

null character, karakter sabiti olarak yazıldığında tek tırnak içinde '\0' içinde yazılıyor. Bu karakterin tam sayı değeri bildiğimiz 0.
null character demek, karakter kodu 0 olan karakter demek.

'A'  -> 0100 0001 -> 65
'\0' -> 0000 0000 -> 0

Ama yazının sonundaki null character'in değeri bildiğimiz 0. Karakter sabiti olarak yazdığımızda, yazıdan bahsettiğimiz vurgusunu kuvvetlendirmek için bunu bir escape sequence olarak yazıyoruz.

'\0' null character

En fazla karşılaştırılan nokta. '0' ile '\0' sabitlerini karıştırmak. 

Tek tırnak içinde 0, 0 karakterinin kodu anlamına geliyor. ASCII de bunun kodu 48.

'0'  -> 0011 0000

Fakat aşağıdaki bildiğimiz düz 0.

'\0' -> 0000 0000

Yazıların bu şekilde tutulmasına null terminated byte stream deniliyor. Yani yazının karakterleri yazının sonunda bu null karaktere rastlayınca kadar devam ediyor anlamında.

C dilinde aksi belirtilmediği sürece yazıların tutulma biçimi budur. null terminated byte stream

---

#include <stdio.h>

int main()
{
    printf("%d\n", '\0'); // -> 0
    int x = '\0'; // -> 0
    int y = 0;

    printf("%d\n", x);
    printf("%d\n", y);
}

---

Fakat aşağıdaki şekilde yazsaydık, kullanılan karakter kodlamasına göre değeri yazdırılacaktı.

printf("%d\n", '0');

0'ın ASCIIdeki kodu 48.

---

Aksi belirtilmediği sürece, bir char dizide tutulan yazının sonunda null karakteri olduğu varsayılarak o yazı kullanılıyor.
Yazılarla ilgili en kaba hata, en sık rastlanan hata, o null karakterin koyulmaması. Yazıyı tutmaya aday kodun o null karakteri koyması unutması.

a) Null karakteri koymayı unutmak.
b) Null karakteri var fakat yanlışlıkla bu karakterin üzerine bir karakter yazılması. Null karakterin ezilmesi.

---

#include <stdio.h>
#define SIZE 100

int main()
{
    char s[SIZE];
}

Bu dizinin boyutu 100. Diyelim ki biz buradaki yazıyı kullanacağız. Yazının sonundaki null karakteri görene kadar, bu yazının uzunluğu bilme şansımız yok.

Buradaki yazının uzunluğu 0 da olabilir ama en fazla 99 olabilir. Çünkü o yazının sonunda null karakter olmak zorunda. Dizinin boyutu 100 olduğuna göre, burada tutulabilecek en büyük yazının uzunluğu 99 olabilir.

char s[SIZE] = "DOGUKAN YAZAR";

Diyelim ki bir kod, yukarıdaki bu yazıyı yazdırmak istiyor. 

Bunu yapmanın yolu, null karakteri görene kadar dönen bir döngü oluşturmak. 

Bizi ilgilendiren bu dizinin tamamı değil, bu dizide tutulan karakterlerle ilgileniyoruz ama uzunluğunu bilmiyoruz.
s dizisinin i indisli elemanı null karakter olmadığı sürece dönen bir döngü deyimi yazıyoruz.
Char türden bir dizide tutulmuş yazıyı standart bir fonksiyona çağrı yapmadan, standart output'a yazdırmak isteseydik, aşağıdaki gibi yapabilirdik.

---- 

#include <stdio.h>
#define SIZE 100

int main()
{
    char s[SIZE] = "DOGUKAN YAZAR";
    ///

    for (int i = 0; s[i] != '\0'; ++i) {
        putchar(s[i]);
    }
    printf("\n");
}

----

#include <stdio.h>
#define SIZE 100

int main()
{
    char s[SIZE] = "DOGUKAN YAZAR";
    int i;
    
    for (i = 0; s[i] != '\0'; ++i) {
        printf("%c  %d\n", s[i], s[i]);
    }

    printf("%d\n", s[i]);
}

----

#include <stdio.h>
#define SIZE 100

int main()
{
    char s[SIZE] = "DOGUKAN YAZAR";

    int i = 0;

    while (s[i])
        putchar(s[i++]);
    
    printf("\n");
}

----

#include <stdio.h>
#define SIZE 100

int main()
{
    char s[SIZE] = "DOGUKAN YAZAR";

    int i = 0;

    while (s[i] != '\0'){
        putchar(s[i]);
        i++;
    }
}

----

Soru 1: yazının karakterlerini döndüğümüz for döngüsünün koşul ifadesinde '\0' yerine 0 yazsak, kodda bir değişiklik olur muydu?

Hayır olmazdı. Çünkü null karakterini karakter sabiti olarak yazmak yerine bu karakterin tam sayı değerini yazıyoruz.
'\0' bir karakter sabiti olarak yazarsak yazıyla ilgili bir iş yaptığımızı vurguluyoruz. 

Soru 2: for döngüsünü aşağıdaki gibi yazsak, bir sorun olur muydu?

for (int i = 0; s[i]; ++i)

Hayır olmazdı. Çünkü for döngüsünün iki noktalı virgül arasındaki ifade lojik yorumlamaya tabii tutuluyor. Non-zero değerler doğru. Zero yanlış.

----

Aşağıdaki kodda tanımsız davranış var mıdır?

#include <stdio.h>
#define SIZE 100

int main()
{
    char s[SIZE];

    s[0] = 'I';
    s[1] = 'R';
    s[2] = 'E';

    for (int i = 0; s[i] != '\0'; ++i){
        putchar(s[i]);
    }
}

Koddaki for döngüsü, yazının sonundaki null karaktere güvenilerek yazılmış.
Yazının sonunda null karakter yok. s dizisi yerel bir dizi, otomatik ömürlü. Hayata çöp değeriyle başlar.
Dizinin 0,1 ve 2 elemanlarına değer atadık fakat 3 indisli elemanı çöp değerle duruyor.
Dolayısıyla çöp değerdeki değişkeni kullandığımız için tanımsız davranış.

----

Aşağıdaki kodda tanımsız davranış var mıdır?

#include <stdio.h>
#define SIZE 100

char s[SIZE];

int main()
{

    s[0] = 'I';
    s[1] = 'R';
    s[2] = 'E';

    for (int i = 0; s[i] != '\0'; ++i){
        putchar(s[i]);
    }

    printf("\n");
}

s dizisi global isim alanında tanımlandığından dolayı ilk değer verilmese de statik ömürlü olduğundan dizinin bütün elemanları hayata 0 değeriyle başlar.
Tanımsız davranış yoktur.

----

Aşağıdaki kodda tanımsız davranış var mıdır?

#include <stdio.h>
#define SIZE 100


int main()
{
    static char s[SIZE];
    
    s[0] = 'I';
    s[1] = 'R';
    s[2] = 'E';

    for (int i = 0; s[i] != '\0'; ++i){
        putchar(s[i]);
    }

    printf("\n");
}

s dizisi statik ömürlü olduğundan dolayı hayata 0 değeriyle başlar.
Tanımsız davranış yoktur.

----

Karakter dizisinin elemanlarını dönen fonksiyon yazmak yerine bu işi yapan iki ayrı standart C fonksiyonu.

Bir tanesi ismi puts olan fonksiyon.

Standart puts fonksiyonu, bizden char türden bir dizinin adresini istiyor.
Dizinin ismini bir ifade içinde kullandığımızda dizinin adresini kullanmış oluyorduk, geçtiğimiz derslerde gördük. Array decay, array to pointer conversion.

Puts fonksiyonunun bizden istediği dizinin başlangıç adresi.
Puts fonksiyonu bu adresteki dizinin tuttuğu yazıyı standart output'a yazdırıyor.

#include <stdio.h>
#define SIZE 100

int main()
{
    static char s[SIZE] = "Dogukan Yazar";

    puts(s);
}

Yazıyı yazdırtıktan sonra, bir de standart output'a new line veriyor.

#include <stdio.h>
#define SIZE 100

int main()
{
    static char s[SIZE] = "Dogukan Yazar";

    puts(s);
    printf("Soner Yazar");
}

Puts variadic bir fonksiyon değil. Yani yalnızca bir adres verebiliriz.
Amacımız salt bir yazıyı standart output'a yazdırmaksa, puts fonksiyonuna o yazının tutulduğu adresi vermek. Dizinin ismini argüman olarak geçmek.

---

Printf fonksiyonu. %s formatlama dönüştürücüsünü char türden bir dizinin adresiyle eşlersek, bu yazıyı yazdıracaktır. Burada new line verilmiyor.

#include <stdio.h>
#define SIZE 100

int main()
{
    static char s[SIZE] = "Dogukan Yazar";

    puts(s);
    printf("%s", s);
}

Printf ile birden fazla dizideki yazıları da standart output'a yazdırabiliriz. Variadic bir fonksiyon olduğu için.

#include <stdio.h>
#define SIZE 100

int main()
{
    char name[SIZE] = "Dogukan";
    char surname[SIZE] = "Yazar";
    int byear = 1994;
    
    printf("%s %s %d yilinda dogdu", name, surname, byear);
}

----

char s[100];

Bu dizi bir yazı tutmak zorunda değil. Çünkü char türü bir tam sayı türü.
Bu dizi, bir yazıyı da tutabilir, sonunda null karakter olan.
Ya da küçük tam sayı değerlerini de tutuyor olabilir.

Fakat aksi belirtilmediği sürece ilk kabulümüz bu char türünden dizi yazıyı tutmak için var.

char s[100];
s[0] = '\0';

İkincisi, C dilinde yazı tutmaya aday bir char dizinin ilk elemanı null karakterse, bu dizi geçerli bir yazıyı tutmaktadır.
Fakat bu dizinin tuttuğu yazı boştur. Yani uzunluğu 0'dır. Bir yazının uzunluğunun 0 olması da normal bir durumdur.
Yazıyı tutmaya aday olan dizinin ilk karakterinin null karakter olmasıyla mümkündür.

----

Char türden dizilere ilk değer verme sentaksı

Char türden dizilere ilk değer verebiliriz. AMA ATAMA YAPAMAYIZ!
Bir dizi ismi, ister char dizisinin ismi olsun, ister int dizisinin ismi olsun, atama operatörünün sol operandı olamaz. Sentaks hatasıdır.

Çünkü dizinin ismini kullandığımız ifade içinde derleyici bunu &s[0] ifadesi olarak ele alacak. 
Adres operatörüyle oluşturulmuş bir ifade de L value expression olmadığı için atama yapmak her zaman sentaks hatasıdır.

Bir char diziye farklı biçimlerde ilk değer verebiliriz.

Karakter sabitleriyle, virgüllerle ayrılan listeyle ilk değer verebiliriz.

char s[100] = {'I', 'R', 'E', 'L', 'A', 'N', 'D'};

----

Aşağıdaki kodda tanımsız davranış var mıdır?

#include <stdio.h>

int main()
{
    char s[100] = {'D', 'O', 'G', 'U'};

    puts(s);    
}

Hiçbir tanımsız davranış yok. Çünkü bir diziye ilk değer verirken, ilk değer verilen öğelerin sayısı, dizinin belirtilen boyutundan daha küçükse, geriye kalan tüm değerler hayata 0 değerle başlar.
Diziye ilk değer vermediğim elemanlar otomatik olarak 0 değeriyle hayata başladı. 0 da null karakter.

----

Aşağıdaki kodda tanımsız davranış var mıdır?

#include <stdio.h>

int main()
{
    char s[] = {'D', 'O', 'G', 'U'};

    puts(s);    
}

Tanımsız davranış var. Dizinin boyutunu belirtmediğimize göre, dizinin boyutu derleme zamanında derleyici ilk değer verilen initializer sayısına bakacak. 
Bu durumda dizinin boyutu 4. Yani null karakter yok.

----

Char türden bir diziye bir yazıyla ilk değer vermek için daha kolay bir sentaks var.

char str[SIZE] = "Dogukan";

Uzun uzun, tek tek karakter karakter kullanmak yerine bu şekilde kullanabiliriz. 

----

Aşağıdaki kodda tanımsız davranış var mıdır?

#include <stdio.h>

int main()
{
    char str[] = "DOGUKAN";

    puts(str);
}

Tanımsız davranış yok. Bu durumda dilin kuralı, boyut belirtmezsek, bu yazının sonundaki null karakter de verilen ilk değerlere dahil.
Dolayısıyla bu dizinin boyutu şuan 7 değil, 8.

Dizinin boyutunu aşağıdaki kodda görebiliriz.

#include <stdio.h>
#include "dutility.h"

int main()
{
    char str[] = "DOGUKAN";

    printf("size(str) = %d\n", asize(str));
}

----

C ile C++ arasında ilginç bir sentaks farklılığı olan bir durum var.

İlk değer olarak verdiğimiz yazı sabitinde, diyelim ki 5 karakter var fakat dizinin belirtilen boyutu da 5. 
Eğer programlama dili C++ olsaydı, aşağıdaki kod sentaks hatası olacaktı.

char str[5] = "TENET";

C++ -> Madem bunun sonuna null karakter de dahil, 5 elemanlı bir diziye, 6 tane initializer ile ilk değer vermiş olduğumuz için bu kod sentaks hatasıdır.

C   -> Bu kod C dilinde geçerli. Dizinin 5 tane elemanı var. Yazının sonunda da null karakter yok.

Burada tanımsız davranış olan dizinin bu şekilde tanımlanması değil. 
Eğer bir tanımsız davranış olacaksa, tanımsız davranış yazının sonunda null karakter olduğuna güvenerek yazıyı dolaşan kodda olacaktır.

char str[5] = "TENET" -> Burada bir tanımsız davranış var mı? Tabiki yok.

puts(str);            -> Bu fonksiyon çağrısında bir tanımsız davranış var mıdır? Tabiki var. puts, yazının sonunda null karakter olduğunu güvendiğinden dolayı tanımsız davranış.

----

Yazının sonunda null karakter olmayan durumlar:

1 - Otomatik ömürlü bir dizi oluşturulumuş, dizinin elemanlarına harflerle ilk değer verilmiş. Ama yazının bitmesi gereken yerde null karakter yok. s[2] çöp değerde.

    char s[100];
    s[0] = 'A';
    s[1] = 'B';

2 - Char türden bir diziye ilk değer veriyoruz fakat ilk değer verirken karakter sabitleriyle ilk değer veriyoruz, dizinin boyutunu da belirtmiyoruz.
    Bu durumda bu dizinin boyutu 5. Dizinin son elemanı E karakterinin kodu, null karakter yok.

    char s[] = {'A', 'B', 'C', 'D', 'E'};

3 - Char türden bir diziye ilk değer veriyoruz fakat ilk değer verirken karakter sabitleriyle ilk değer veriyoruz, dizinin boyutunu da belirtiyoruz.
    Bu durumda bu dizinin boyutu 5. Dizinin son elemanı E karakterinin kodu, null karakter yok.

    char s[5] = {'A', 'B', 'C', 'D', 'E'};

4 -  Char türden bir diziye ilk değer veriyoruz ve çift tırnak içerisinde bir yazıyla ilk değer veriyoruz. Yazıdaki karakter sayısıyla dizinin belirtilen boyutu aynı.
    Bu durumda C++ dilinde sentaks hatası. C dilinde ise geçerli. Yazının sonunda null karakter yok.

Eğer dizi statik ömürlüyse, zaten dizinin ilk değer verilmeyen elemanlarının değeri 0 oluyor.

-----

Standart input'dan gelen bir yazıyı, char türünden bir diziye nasıl yerleştirebiliriz?

Bu işi yapan standart C fonksiyonları var ama öncesinde herhangi bir fonksiyon kullanmadan döngü deyimiyle nasıl yapıldığını görelim.

---

#include <stdio.h>

#define SIZE 100

int main()
{
    char str[SIZE];
    int c;
    int idx = 0;

    printf("Bir yazi girin: ");
    while ((c = getchar()) != '\n') {
        str[idx++] = c; 
    }

    str[idx] = '\0';

    printf("Girilen yazi (%s)\n", str);
}

---

Standart olan fonksiyonlar.

scanf fonksiyonu. Dikkat edilmesi gereken nokta taşma hatası bizim sorumluluğumuzda. 
scanf ile aldığımız yazı, dizinin boyutundan yüksekse, run-time hatasıdır. Tanımsız davranış.

#include <stdio.h>

#define SIZE 100

int main()
{
    char str[SIZE];

    printf("Bir yazi girin: ");
    scanf("%s", str);

    printf("Girilen yazi (%s)\n", str);
}

---

Yukarıdaki programı derleyip çalıştırdığımızda, standart input'a "dogukan yazar" yazısını girersek, sadece dogukan yazısını alacaktır.
Çünkü scanf whitespace karakterleri ayıraç olarak alıyor. scanf ilk boşluk karakterini seperator olarak alacak.
Dolayısıyla eğer gelen karakterleri bir char diziye yerleştirmek istiyorsak,
boşluk karakterlerini scanf ile yazıya doğrudan, formatlama biçimi olmadan aktarmamız gerekir.

Ayrıca scanf, null karakteri de kendisi yazıyor. Yani scanf'e çağrı yaparsak, null karakterin yazıldığını bilmemiz gerekiyor.

1 - scanf kullanırken risk var çünkü dizinin boyutunu kontrol etme şansına sahip değil. Taşma olabilir.

2 - scanf kullanırsak boşluklu bir yazıyı, %s ->böyle bir formatlamayla, yazıyı boşluk karakterleriyle diziye alamayız.

---

whitespace karakterlerinin scanf'de ayraç olarak kullanılmasının pozitif yönleri:

#include <stdio.h>

#define SIZE 100

int main()
{
    char name[SIZE];
    char surname[SIZE];
    int age;

    printf("Isim, soyisim ve yasinizi giriniz: ");
    scanf("%s%s%d", name, surname, &age);

    printf("%d yasindaki %s %s\n", age, name, surname);
}

---

gets_s

C dilinin 2021 standartlarıyla eklenen bir fonksiyonu.

Bu fonksiyon bizden bir dizinin adresini ve boyutunu istiyor.

Birinci parametreye dizinin adresini, ikinci parametreye dizinin boyutunu geçiyoruz.

#include <stdio.h>
#define SIZE 10


int main()
{
    char str[SIZE];

    printf("Bir yazi giriniz: ");
    gets_s(str, SIZE);
}

Neden dizinin boyutunu geçiyoruz? Pointer hatası söz konusu olmasın diye. Çünkü dizinin boyutunu aldığı için, diziye en fazla SIZE - 1 tane karakter yazacak.

Diyelim ki gets_s'i aşağıdaki gibi çağırdık ve standart inputun bufferından 20 tane karakter geldi.
O zaman 9 tanesini ilgili diziye yazacak ve sonuna null karakteri koyacak. Yani bu fonksiyon aslında bize diyor ki, ben diziyi taşırmama sözü veriyorum.

#include <stdio.h>
#define SIZE 10

int main()
{
    char str[10];

    printf("Bir yazi giriniz: ");
    gets_s(str, 10);

    printf("(%s)\n", str);
}

----

Ayrıca derleyiciler gets_s fonksiyonu için ayarları değiştirmişler. Geçici olarak dutility.h başlık dosyasında kendimiz sgets isimli bir fonksiyon tanımladık.

#include <stdio.h>
#include "dutility.h"
#define SIZE 100

int main()
{
    char str[SIZE];

    printf("Bir yazi giriniz: ");
    sgets(str);

    printf("(%s)\n", str);
}

---------

Yazının Uzunluğunu Bulmak - null karakter görene kadar dönen bir döngü, döngünün her turunda yazının uzunluğunu tutacak bir sayacı arttıracağız.

#include <stdio.h>
#include "dutility.h"
#define SIZE 100

int main()
{
    char str[SIZE];

    printf("Enter a string: ");
    sgets(str);
    
    int i;
    
    for (i = 0; str[i] != '\0'; ++i)
        ;
    
    printf("Character Length: %d\n", i);
}

---------

#include <stdio.h>
#include "dutility.h"
#define SIZE 100

int main()
{
    char str[SIZE];
    printf("Enter a string: ");
    sgets(str);

    int len = 0;

    while (str[len] != '\0')
        ++len;
    
    printf("length of a string: %d\n", c);
}

---------

Yazının Sonuna Bir Harf Eklemek - Yazının sonundaki null karakteri bulacağız, null karakterin yerine X yazacağız, ondan bir sonraki karaktere de null karakter yazacağız.

#include <stdio.h>
#include "dutility.h"
#define SIZE 100

int main()
{
    char str[SIZE];

    printf("Enter a string: ");
    sgets(str);
    
    int i;
    
    for (i = 0; str[i] != '\0'; ++i)
        ;
    
    str[i] = 'X';
    str[i + 1] = '\0';

    printf("(%s)\n", str);
}

---------

Yazıda istenilen karakterin kaç tane olduğunun bulunması

#include <stdio.h>
#include <ctype.h>
#include "dutility.h"
#define SIZE 100

int main()
{
    char str[SIZE];
    int c, count = 0;

    printf("Bir yazi giriniz: ");
    sgets(str);
    printf("[%s]\n", str);
    
    printf("Aranacak karakteri giriniz: ");
    c = getchar();

    for (int i = 0; str[i] != '\0'; ++i)
        if (toupper(str[i]) == toupper(c))
            ++count;

    printf("%c harfinden %d tane var.\n", c, count);
}

---------

Yazıdaki bütün harf karakterlerini sayacağız. ASCII karakter kodlaması kullanıldığının garantisi var. 
A harfinden kaç tane var, B harfinden kaç tane var, hepsinin listesini yazacağız.

26 tane harf karakteri olduğuna göre, her birini sayacağımız için 26 tane sayaca ihtiyacımız var.
ASCII'de harf karakterleri ardışık olarak yer alıyor. Her kodlama sisteminde böyle değil tabiki.

Bir dizi alacağız ve bu dizinin elemanlarını sayaç olarak kullanacağız.
Bu dizinin ilk elemanı A harfinin sayacı, ikinci elemanı B harfinin sayacı, üçüncü elemanı C harfinin sayacı diye son elemanı Z harfine kadar gidiyor.

++counts[toupper(str[i]) - 'A']; -> Program bu noktaya geldiğinde, A'dan Z'ye kadar olan büyük harf karakterlerinden birinin kodu demek.
Bu karakterler ASCII'de tek bir blok olduğuna göre, bu karakterden A harfinin kodunu çıkartırsak, A için 0, B için 1, C için 2 değerlerini elde edeceğiz.
Yani bizim counts dizimiz, sayaç dizimiz için indeks bilgisini elde edeceğiz.
counts dizisinin bu indisli elemanı, str[i] hangi harf karakterse, onun sayacı olacak. ++ operatörüyle bu karakterin değerini arttırıyoruz.

#include <stdio.h>
#include <ctype.h>
#include "dutility.h"
#define SIZE 100

int main()
{
    char str[SIZE];
    int counts[26] = { 0 };

    printf("Bir yazi giriniz: ");
    sgets(str);
    printf("[%s]\n", str);

    for (int i = 0; str[i] != '\0'; ++i)
        if (isalpha(str[i])) {
            ++counts[toupper(str[i]) - 'A'];
        }

    for (int i = 0; i < 26; ++i)
        if (counts[i] != 0)
            printf("%c  %d\n", 'A' + i, counts[i]);
}

---------

Bir Yazının Ters Çevrilmesi - to reverse a string

Döngünün dönüş sayısı, dizinin boyutu değil, dizinin tuttuğu yazının uzunluğu olmalı.

#include <stdio.h>
#include "dutility.h"
#define SIZE 100

int main()
{
    char str[SIZE];
    printf("Bir yazi girin: ");
    sgets(str);
    printf("[%s]\n", str);

    int len = 0;

    for (int i = 0; str[i] != '\0'; ++i)
        ++len;

    for (int i = 0; i < len / 2; ++i) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }

    printf("[%s]\n", str);
}

---------

ÖDEV:

Ana, Naci Dede ne dedi Canan'a?
Kalas yok kütük koy, Salak!
Para hazır ama Rıza harap!!
at sahibi gibi hasta.
en iyi meşe beşe mi yine???

Madam, I'm Adam!
A man, a plan, a canal: Panama

Bu tür cümlelere palindrom deniliyor. Palindromik cümleler. Cümleleri sadece harf karakterlerini dikkate alıp, düzden ve tersten okunması aynı.

Bizden istenilen, girilen yazının palindrom olup olmadığını test edeceğiz.
Palindrom ise, palindrom yazacak. Palindrom değilse, palindrom değil yazacak.

Soruyu çözme şekilleri:

a) ilave bir dizi kullanarak, yani birinci dizinin dışında ikinci bir dizi kullanabiliriz
b) sadece str dizisini kullanarak ve bu diziyi değiştirmeden

---------

ÖDEV:

İki kelime giriniz. Girişin bu şekilde olduğunun garantisi var. "dogukan yazar" gibi
Yapmamız gereken bu kelimelerin yerini değiştirmek.

dogukan yazar
yazar dogukan

İkinci bir dizi kullanılmayacak. Değişken tanımlayabiliriz.

---------

ÖDEV:

Bir yazı giriniz. Noktalama işaretleri yok fakat kelimelerin arasında istenildiği kadar boşluk karakteri olabilir. "  dogukan        yazar   soner    yazar   " gibi.
Yazının başında veya sonunda boşluk karakterleri olabilir.
Yapmamız gereken girilen kelime sayısını bulmak.

İkinci bir dizi kullanılmayacak.

---------

ÖDEV:

    char s1[SIZE];
    char s2[SIZE];

    printf("Iki kelime girin: ");
    scanf("%s%s", s1, s1);
    printf("[%s] [%s]\n", s1, s2);

Bu iki kelimeyi karşılaştıracağız. İki kelimenin eşit olup olmadığını sınayınız. Eşitse eşit, eşit değilse eşit değil yazdıracağız.


----------------

Birinci kelimenin sonunda ikinci kelimeyi ekleyin.

#include <stdio.h>
#include <ctype.h>
#include "dutility.h"
#define SIZE 100

int main()
{
    char s1[SIZE];
    char s2[SIZE];

    printf("Iki kelime girin: ");
    scanf("%s%s", s1, s2);
    printf("[%s] [%s]\n", s1, s2);
    //Birinci kelimenin sonuna ikinci kelimeyi ekleyin.

    int i, k;

    for (i = 0; s1[i] != '\0'; ++i)
        ;
    for (k = 0; s2[k] != '\0'; ++k){
        s1[i + k] = s2[k]; 
    }

    s1[i + k] = '\0';

    printf("[%s] [%s]\n", s1, s2);
}

----------------

ÖDEV:

Kullanıcıdan bir yazı ve bir silinecek karakter bilgisini alıp, silinmesi istenilen karakteri yazıdan siliniz.

Test Kodu:

#include <stdio.h>
#include <ctype.h>
#include "dutility.h"
#define SIZE 100

int main()
{
    char str[SIZE];
    int ch;

    printf("Bir yazi giriniz: ");
    gets(str);
    printf("[%s]\n", str);
    printf("Silinecek karakteri giriniz: ");
    ch = getchar();

    //code
}

*/

