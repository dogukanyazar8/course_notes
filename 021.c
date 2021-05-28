/*

Ders21

Explicit Type Conversion

--------------

Tür Dönüştürme Operatörü

Aşağıdaki programda, toplam değerini tutan sum ile adet değerini tutan n değişkenleri var.
Diyelim ki, bizim sum'ı n'e bölerek ortalamayı bulmamız gerekiyor ama ortalamanın gerçek sayı türünden olması lazım.

Eğer tür dönüştürme operatörü olmasaydı aşağıdaki gibi bir hile ile bunu yaptırabiliriz.

#include <stdio.h>

int main()
{
	int sum = 100;
	int n = 3;

	double mean = 1. * sum / n;

	printf("%f", mean);
}

Tabiki böyle bir kod yazmamıza gerek yok, tür dönüştürme operatörünü kullanabiliriz.

Tür Dönüştürme Operatörü - Typecast Operator

(type) -> operatörün atomları açılan kapanan parantez, parantez içine hangi türü yazarsak, operand o türe dönüştürülecek.

(int)dval -> derleyiciye dval'i int türüne dönüştür talimatı veriyoruz.

--------------

#include <stdio.h>

int main()
{
	int sum = 100;
	int n = 3;

	double mean = (double)sum / n;

	printf("%f", mean);
}

--------------

#include <stdio.h>

//int türünü 2 byte kabul edelim.
//long türünü 4 byte kabul edelim.

int main()
{
	int x, y;

	printf("Iki tamsayi giriniz: ");
	scanf("%d%d", &x, &y);

	(long)x * y // ikisi de int türden, çarpma işlemi int türünden yapılacak. operandlardan birini long türüne cast edersek, işlem 4 bytelık long türüne yapılacak ve veri kaybı olma ihtimali azalacak.
}

--------------

Tür dönüştürme operatörünün kullanıldığı senaryolar.

Bunların bir kısmı pointerlarla ilgili. Bir işlemi bizim istediğimiz türde yaptırmak için bu operatörü kullanabiliriz.

Tür dönüştürme operatörünün kullanıldığı birinci senaryo;

İşlem benim istediğim türde yapılmıyor, benim istediğim türde yapılması için tür dönüşümü operatörünü kullanıyorum.

Tür dönüştürme operatörünün kullanıldığı ikinci senaryo;

Tür dönüşümü zaten yapılacak, operatörü kullanmasak da, ama ortada bir veri kaybı var. Ve biz diyoruz ki, biz bunu bilerek isteyerek yapıyoruz, okuyana bu bilgiyi veriyoruz.
Derleyicinin uyarı mesajını kesmek için tür dönüştürme operatörünü kullanıyoruz.

#include <stdio.h>

int main()
{
	double dval;
	int ival;

	printf("Bir gercek sayi giriniz: ");
	scanf("%lf", &dval);

	ival = dval; //sentaks hatası değil, duruma göre tanımsız davranış olabilir, olmayabilir. Böyle bir kod yazmamalıyız, kodu okuyan bunu yanlış yazdığımızı düşünür, derleyici de uyarı mesajı verir.
}

Ama biz yukarıdaki ival = dval ifadesini bilerek, isteyerek yazmışsak, bu ifadedeki dval'i int türüne cast edeceğiz.

ival = (int)dval

Özellikle veri kaybı riski olan, büyük türden küçük türe yapılan dönüşümlerde, mutlaka bu operatörü kullanmalıyız.

--------------

#include <stdio.h>

void func(float);

int main()
{
	double dval;

	printf("Bir gercek sayi giriniz: ");
	scanf("%lf", &dval);

	func(dval);
}

Parametre değişkeni float türden olan bir fonksiyon var ama bu fonksiyona double türden bir argümanla çağrı yapıyoruz.

Bunu bilerek yapıyorsak, func((float)dval)

--------------

Tür dönüştürme operatörü ile oluşturulan ifadeler sağ taraf değeri ifadeleridir. R value expression
Yani sol taraf değerinin kullanılması zorunlu bir yerde bu operatörü kullanamayız.

#include <stdio.h>

int main()
{
	int ival;

	(double)ival = 12;
}

error C2106: '=': left operand must be l-value

--------------

#include <stdio.h>

int main()
{
	int min, sec;

	printf("Dakika ve Saniye Degerlerini Girin: ");
	scanf("%d%d", &min, &sec);

	printf("%d dakika ve %d saniye %f saat yapar.\n", min, sec, min / 60 + sec / 3600);
}

Dakika ve saniye degerlerinin saat olarak hesaplanması için yazdığımız ifade yanlış. Çünkü;

min / 60 ifadesinden elde edilen değer int türden, 
sec / 3600 ifadesinden elde edilen deger double türden.

Sabitleri gerçek sayı sabiti türünden yaparsak, işlemler double türünden yapılacak.

min / 60. + sec / 3600.

--------------

Çok sık kullanılan bir idiom.

#include <stdio.h>

int main()
{
	double dval;
	printf("[-5 ile 5] araliginda gercek sayi giriniz: ");
	scanf("%lf", &dval);

	printf("girilen sayi: %f yuvarlama sonucu %d\n", dval, (int)(dval > 0. ? dval + .5 : dval - .5));
}

--------------

#include <stdio.h>

int factorial(int x)
{
	return x < 2 ? 1 : x * factorial(x - 1);
}

int main()
{
	double sum = 0.;

	for (int i = 0; i < 10; ++i) {
		sum += 1 / factorial(i);
	}

	printf("sum = %f", sum);
}

--------------

Rastgele Sayı Üretimi - Random Number Generation

Programlama yoğun olarak ihtiyaç duyulan bir konu. 

Mesela 7 rastgele bir sayı mıdır? Bu soru doğru değil çünkü rastgelelikten bahsedilmek için elimizde bir sayı sekansı olması gerekiyor.

Tek bir sayının rastgele olma olasığı yoktur.

7 2 9 1 6 5 2 ? -> Bu sayılar biraz daha mantıklı.

Rastgelelik öngörülemezlik değeridir.

7 7 7 7 7 7 7 ? -> Burada öngörülemezlik çok çok düşük.

1 4 7 2 3 1 4 7 2 3 1 4 7 2 3 1 ? -> Öngörülebilirlik yüksek, rastgelelik düşük.

Mesela hemen her oyun programında bir rastgele sayı üretimi var.

Test işlemlerinde test verisinin oluşturulmasında rastgele sayı üretiminden faydalanılıyor.

Bazı algoritmalar, mesela genetik algoritma kategorisi rastgele sayı üretimiyle ilgili.

Kriptoloji, rastgele sayı üretiminin en çok kullanıldığı yerlerden biri.

Simulasyon, rastgele sayı üretiminin en çok kullanıldığı yerlerden biri.

Matematik, olasılık hesaplama.

--------------

True Random Number Generation (Gerçek Rastgele Sayı Üretimi)
	Rastgele sayı üretiminin doğadan kaynaklanan yani matematiksel bir süreç yok, doğrudan doğadaki olaylardan faydalanıyor.
	Atmosferdeki en sık kullanılan teknik, atmosferdeki gürültüden faydalanmak.
	
Psedo Random Number Generation (Sözde Rastgele Sayı Üretimi)
	Burada bir rastgelelik falan yok, matematiksel bir süreçle, algoritmik bir yöntemle, sayıları elde ediyoruz. Ve elde ettiğimiz sayılar rastgele olduğu izlenimi veriyor.

Rastgeleliğin tek bir kriteri yok. 10'a yakın kriterle ölçülüyor, iyi bir algoritma bu kriterlerin önemli bir kısmını sağlayabiliyor.

--------------

True Random Number Generation (Gerçek Rastgele Sayı Üretimi)

Avantajı: Doğadan kaynaklı, öngörülemezlik çok çok yüksek.
Dezavantajı: Bir tanesi yavaş olması, çünkü bunun için dışsal, external bir aygıt kullanmamız gerekiyor atmosferdeki gürültüyü ölçme örneği gibi.
İkincisi, tekrar edilebilir değil. Bu şekilde bir gerçek sayı üreticisi kullanılırsak, belli bir sayıda rastgele sayı üretsek, bunu tekrar üretmek istediğimizde bunun imkanı yok.

İçinde balık olan bir akvaryum düşünelim ve bizden bi rastgele sayı üretmemiz isteniliyor. Bizde rastgele sayı üretmemiz gereken yerde, balık sağa giderse 1 sola giderse 2, yukarı giderse 3 gibi değerler üretiyoruz. 
Bu balığın nereye gideceğini bilemeyiz, buradan elde edilecek sayılar yüksek rastgelelik içerecek. 

Ama aynı sayı zincirini, aynı yöntemi kullanarak elde etmemiz mümkün olmayacak.

--------------

Psedo Random Number Generation (Sözde Rastgele Sayı Üretimi)

Gerçek rastgele sayı üretimi yöntemi gibi değil. Algoritmik bir yöntem kullanılıyor. İnsanlar 1500lü yıllardan başlayarak sözde rastgele sayı üretimi için algoritmalar geliştirmişler.

İlk kullanılan algoritmalardan biri, bir değer alıyoruz, bu algoritmayı tetikleyen değere seed value deniliyor.
Bu sayının karesini alıyoruz ve karesinin ortasındaki mesela 5 basamağı ilk rastgele sayı olarak aldık,
Bir sonraki rastgele sayı üretiminde bu sayının karesinin baştaki ve sondaki basamağı attık, bunun ortasındaki 5 basamağı ikinci rastgele sayı olarak verdik.
Sürekli bu işlemi tekrar ediyoruz. 

Şimdi burada, aynı seed value değerini kullanırsak, aynı rastgele sayı zincirini elde ederiz.
Ama diğer taraftan, bu gerçek bir rastgelelik değil.

Endüstride en çok kullanılan algoritmalar

Mersenne Twister Algoritması. Bir çok programlama dilinin standart kütüphanesinde bu algortimayı gerçekleştiren bir modül bulunuyor ama C'de standart değil.
C++ bütün programlama dili içinde, standart kütüphanesinde rastgele sayı üretimine destek veren programlama dili olabilir.
C dilinde ise, minimal düzeyde destek veriliyor. Tabi standart kütüphaneden bahsediyoruz.

Rastgele sayı üreticisinin kalitesinin ne olduğu, yaptığımız işin kritikliğiyle ilgili.
Rastgeleliğin çok kritik olmadığı yerde C'nin standart fonksiyonu kullanılabilir.

Rastgele sayı üreticisinin yaptığı iş rastgele 0 ve 1 üretmek. büyük ihtimalle bunları bi işaretli tam sayı türünden verecek ama ürettiği 1 ve 0.
Bu rastgele üretilen 1 lerin ve 0 ların, nasıl bir dağılım stratejisi, modeliyle nasıl bir aralığa dağıtılacağı tamamen başka bir kodla belirleniyor.

Örnek olarak tavla oyununda, zarlardan birini rastgele olarak üreteceğiz. 

En küçük değer: 1
En büyük değer: 6

Şimdi bizim bir şekilde, rastgele sayı üreticimizin ürettiği 1leri ve 0lar uniform olarak 1 - 6 kapalı aralığına dağıtmamız gerekiyor. Bunu yapan genel olarak başka bir kod.
Bu dağıtım modeline uniform distribution deniliyor.

Diğer taraftan, bir test programı yazdığımızı düşünelim, test programı için insanların boylarını, kilolarını oluşturmamız gereksin.
Şimdi burada uniform dağılım yaparsak, hiç gerçekci olmaz. Şöyle diyemeyiz, en küçük kiloyu 40 alalım, en fazla kiloyu da 180 alalım ve bu aralıkta rastgele kilolar üretelim.
Ama doğada, normal dağılım var. Bu örnekteki gibi bir çok dağılım modeli var. Rastgele sayıları belirli bir dağıtım modeliyle dağıtmamız gerekiyor.

C dilinde rastgele sayı üretimiyle alakalı iki tane fonksiyon var.
Bu fonksiyonlar <stdlib.h> başlık dosyasında bildirilmiş.

Fonksiyonlardan birinin ismi rand, geri dönüş değeri int.
Diğeri srand, geri dönüş değeri yok, parametresi unsigned int.

int rand(void);
void srand(unsigned int);

rand fonksiyonu, rastgele sayı üreten fonksiyon. her çağırdığımızda bize 0 ile RAND_MAX makrosunun değeri olan sözde uniform dağıtılmış bir rastgele sayı üretiyor.

0 - RAND_MAX -> Bu RAND_MAX makrosu, stdlib.h başlık dosyasında tanımlanan bir makro. 

Derleyicilerin hemen hepsinde, RAND_MAX makrosunun define edildiği değer 32767. 2 bytelık işaretli int türünün maksimum değeri.

--------------

#include <stdio.h>
#include <stdlib.h>

int main()
{
	for (int i = 0; i < 10; ++i) {
		printf("%d\n", rand());
	}
}

Ekran Çıktısı:

41
18467
6334
26500
19169
15724
11478
29358
26962
24464

--------------

Bilgisayarın gerçek anlamda rastgele sayı üretmesinin imkanı yok. Bilgisayar deterministik bir makina. Hangi inputu verirsek, o outputu alırız.

Dolayısıyla burada kullanılan algoritma bir tohum değerinden bir hareketle bu işi yapıyor. Aynı tohum değeriyle üretilecek rastgele sayı zinciri aynı.
Biz yukarıdaki programı bir kez daha çalıştırırsak, rastgele ilk 10 sayıların, aynı olduğunu görürüz.

Yani tek bir tohum değeri için tek bir zincir var. O zaman bu tohum değerini değiştirirsek, yeni bir zincir elde ederiz.
Bu tohum değerini set eden fonksiyon srand.

Eğer srand ile tohum değerini set etmezsek, default tohum değeri 1.

--------------

#include <stdio.h>
#include <stdlib.h>

int main()
{
	//default seed value = 1
	srand(345);
	for (int i = 0; i < 10; ++i) {
		printf("%d\n", rand());
	}
}

--------------

Her tohum değeri için ayrı bir zincir var. srand fonksiyonunun parametresi unsigned int olduğuna göre, unsigned int bu sistemde bu derleyicide 4 byte.

O zaman 4294967295 farklı rastgele sayı zinciri olacak.

--------------

#include <stdio.h>
#include <stdlib.h>
#include "dutility.h"

int main()
{
	for (int i = 1; i < 1000; ++i) {
		printf("Seed Value: %d\n", i);
		for (int k = 0; k < 100; ++k) {
			if (k && k % 10 == 0)
				printf("\n");
			printf("%5d ", rand());
		}
		putline();
		getchar();
		system("cls");
	}
}

--------------

#include <stdio.h>
#include <stdlib.h>
#include "dutility.h"

int main()
{
	int seed;

	printf("Tohum degeri: ");
	scanf("%d", &seed);
	srand(seed);

	for (int i = 0; i < 10'000'000 - 1; ++i)
		rand();

	printf("Uretilen 10 milyonuncu sayi: %d\n", rand());
}

Tohum degeri: 765123
Uretilen 10 milyonuncu sayi: 13356

Programı tekrar çalıştırıp aynı tohum değerini verdiğimizde, 10 milyonuncu sayı aynı olacaktır.
Her tohum değeri için tek bir sayı zinciri var.

--------------

Diyelim ki üretilen rastgele sayıları, belirli bir aralıkta uniform olarak dağıtmak istiyoruz.
Rastgele dağıtımın önemli olduğu yerlerde asla % operatörü ile kullanmamak gerekir.

Tavla Zarı Üretme

#include <stdio.h>

int main()
{
	for (int i = 0; i < 1000; i++) {
		printf("%d ", rand() % 6 + 1);
		getch();
	}
}

--------------

#include <stdio.h>

int main()
{
	int year_min, year_max;
	printf("en kucuk ve buyuk yillari giriniz: ");
	scanf("%d%d", &year_min, &year_max);

	for (int i = 0; i < 100; ++i) {
		printf("%d ", rand() % (year_max - year_min + 1) + year_min);
		getchar();
	}
}

--------------

#include <stdio.h>

int main()
{
	for (int i = 0; i < 100; ++i) {
		printf("%d %d", rand() % 6 + 1, rand() % 6 + 1);
		getchar();
	}
}

Biz bu program tekrar çalıştırdığımızda aynı tohum değerinden aynı sayı zincirini elde ettiğimiz için aynı zarlar gelecek.
Bazı yerlerde bu avantaj olabilir fakat böyle oyun gibi yerlerde bu bir dezavantaj.

Bu sorunu gidermek için tohum değerini aşağıdaki gibi rastgele vermek sorunu çözmeyecektir.

#include <stdio.h>

int main()
{
	srand(rand()); // (Böyle yazmakla, aşağıdaki gibi yazmak arasında bir fark yok çünkü 1 tohum değeriyle üretilen ilk sayı 41.)
	//srand(41);

	for (int i = 0; i < 100; ++i) {
		printf("%d %d", rand() % 6 + 1, rand() % 6 + 1);
		getchar();
	}
}

Program her çalıştırıldığında farklı bir sayı zinciri oluşturmanın yolu bu değil.
İki yolu var.

Birincisi tohum değerini gerçek rastgele sayı üreticisinden almak. Artık modern işletim sisteminlerinde bir takım fiziksel faktörlerden hareketle, gerçeye yakın rastgele sayı üretimi mümkün.
İşlemcisinin ısınmasını ölçülmesi veya klavyede tuşların basılmasındaki süre aralığı. Tohum değerini böyle bir gerçek rastgele sayı üreticisinden alırız.
Böylece program her çalıştığında farklı bir tohum değeri gelebilir.

İkincisi ise randomize ismindeki idiom. Rastgele sayı üreticisini set eden fonksiyona belirli bir orjinden fonksiyonun çağrıldığı zamana kadar geçen saniye sayısını argüman olarak veriyoruz.
Bu durumda program yeniden çalıştırıldığında daha fazla saniye geçmiş olacak ve tohum değeri farklı olacak.

Standart kütüphanemizin time.h başlık dosyasında bildirilen time isminde bir fonksiyon var.
Bu fonksiyona 0 değeri ile çağrı yaparsak, aslında bu null pointer dediğimiz bir değer, bu fonksiyonun geri dönüş değeri sistemden sisteme fakrlı olabilir, epoch denilen bir değer.
Benim sistemimde epoch -> 1 1 1970 00:00

Bu fonksiyonu çağırdığımda, bu fonksiyonun geri dönüş değeri 1 1 1970 00:00'dan, fonksiyonun çağrıldığı noktaya kadar geçen saniye sayısı.
 
--------------

#include <stdio.h>

int main()
{
	printf("%lld\n", time(0));
}

--------------

time fonksiyonunu, srand fonksiyonuna argüman olarak verirsek, bu programı her çalıştırdığımızda farklı bir sayı zinciri oluşturulacak.

srand fonksiyonunun, time fonksiyonunun geri dönüş değeri ile çağrılması idiomuna, randomize idimou deniliyor.

time fonksiyonunun geri dönüş değeri, derleyiciye bağlı olarak signed long veya signed long long olabilir fakat srand fonksiyonunun parametresi unsigned int.
Bu durumda veri kaybı olacağı endişesiyle derleyici bize uyarı mesajı verebilir, bunu bilerek isteyerek yaptığımız için tür dönüştürme operatörünü kullanabiliriz.

Derleyici Warning Mesajı: conversion from 'time_t' to 'unsigned int', possible loss of data

Randomize Idiomu -> srand((unsigned int)time(0));

Sık kullanılan bir idiom olduğu için dutility.h başlık dosyasında fonksiyonel makro olarak tanımlıyorum.

--------------

#include <stdio.h>
#include <stdlib.h>
#include "dutility.h"

int main()
{
	randomize();

	for (int i = 0; i < 10; ++i) {
		if (i && i % 10 == 0)
			printf("\n");
		printf("%5d ", rand());
	}
}

Ekran Çıktısı:

20928  1149 28550  8730 30469  6980 19127  6201 19153  5539

--------------

#include <stdio.h>
#include <stdlib.h>
#include "dutility.h"
#include <ctype.h>

int get_random_char(void)
{
	int c;

	while (!isupper(c = rand() % 128)) //ASCII Kodları, 0 - 128 arası, c'ye atandı. isupper ile c'nin büyük harf olup olmadığını kontrol ettik.
		;

	return c;
}

int main()
{
	for (;;) {
		putchar(get_random_char());
		_getch();
	}
}

--------------

Popüler mülakat sorulardan bir tanesi:

--------------

#include <stdio.h>
#include <stdlib.h>
#include "dutility.h"
#include <ctype.h>

void printf_random_psw(void)
{
	randomize();
	int len = rand() % 8 + 5; //len degiskeni, yazdirilacak parolanın karakter olarak uzunluğunu tutuyor.

	while (len--) {
		putchar(rand() % 26 + 'a'); //ASCII'de 26 tane harf karakteri var. Küçük harf a'nın kod numarasına, 0 - 25 aralığında bir tam sayı eklersem, elde ettiğim değer rastgele bir küçük harf kodu olacak.
	}

	putchar('\n');
}

int main()
{
	for (int i = 0; i < 10; ++i) {
		printf_random_psw();
	}
}

Bu programda herhangi bir hata var mıdır?

Evet var. Hatanın nedeni, randomize fonksiyonunu, fonksiyon içinde çağırdık. Bu döngü o kadar hızlı çalışıyor ki, bu fonksiyon bir daha çalışana kadar saniye atlamıyor.

Bunun sonucunda üreteceği 10 rastgele sayı da aynı olacaktır. 

Ekran Çıktısı:

fazddmaeu
fazddmaeu
fazddmaeu
fazddmaeu
fazddmaeu
fazddmaeu
fazddmaeu
fazddmaeu
fazddmaeu
fazddmaeu

Eğer for döngüsündeki sayıyı aşağıdaki gibi arttırırsak, her 1 saniyede üretilen rastgele sayı değişecek.

	for (int i = 0; i < 100000; ++i) {
		printf_random_psw();
	}

Hata randomize'ın çağrıldığı yerde. Bu tür durumlarda randomize idiomunun döngüsel bir yapıda veya fonksiyon içinde değil, rastgele sayı üretiminin başlamasından önce tipik olarak main fonksiyonda çağrılması gerekiyor.

--------------

Olasılık Hesabı

Yazı Tura'daki, yazı gelme olasılığının yüzdesi, para atma sayısı, sonsuza yakınsandığında kaç tane yazı gelecek, bunun yüzdesi nedir.

Dolayısılıyla herhangi bir olasılık problemini, bir fiilen onu simule eden kod yazarız, bütün ihtimalleri rastgele sayı üreticisiyle üretiriz.

Belirli bir değerin geldiğini, oluştuğunu hesaplayabiliriz.

--------------

Yazı Tura Örneği

#include <stdio.h>
#include <stdlib.h>

#define HEADS 0
#define NTOSS 100'000

int main()
{
	int heads_count = 0;

	for (int i = 0; i < NTOSS; ++i) {
		if (rand() % 2 == HEADS)
			++heads_count;
	}

	printf("Tura gelme olasiligi: %.12f\n", (double)heads_count / NTOSS);
}

--------------

Craps Oyunu

Kasaya karşı 2 tane zar atıyoruz. Bildiğimiz tavla zarı. 

Attığımız zarın toplamı 7 veya 11 gelirse, bunlar kazanan sayılar. Koyduğumuz paranın iki katını alıyoruz.
Attığımız zarın toplamı 2 - 3 - 12 gelirse, bunlar kaybettiren sayılar. Parayı kaybediyoruz.

Attığımız zarın toplamı 4 - 5 - 6 - 8 - 9 - 10 gelirse, oyunun sonuca bağlanması için oyuncu sürekli zar atıyor. 
İlk attığı zarı tekrar atmaya başarırsa, kazanacak. İlk attığı zarı tekrar atamadan 7 atarsa, kaybedecek. Artık yukarı sayıların bir önemi yok.

Mesela zarı attık, 12 geldi, kaybettik.
Mesela zarı attık, 11 geldi, kazandık.
Mesela zarı attık, 8 geldi, artık sürekli zar atacağız. 8 atarsak kaybedeceğiz, 7 atarsak kaybedeceğiz. 8 ya da 7 dışında artık hiçbir sayının önemi yok.

Mesela zarı attık, 10 geldi, tekrar atıyoruz, 2 geldi, tekrar atıyoruz, 5 geldi, tekrar attık 7 geldi, kaybettik.

Böyle oyunlara çifte şans oyunları deniliyor. Yani kasanın kazanma olasılığıyla, oyuncunun kazanması olasılığı birbirine çok yakın.

Kasaya bir avantaj sağlamak için, çifte şans oyunlarında yüzdeler %50 - %50 değil. Kasanın kazanması oranı %50.70 olsun, oyuncunun kazanma oranı %49.30 olsun.

Genellikle %49.20 gibi bir sabit oluyor.

Ayrıca rastgele sayı üreticisinin ve dağılım kodunun kalitesi. 

Önce bu kodu C'nin standart fonksiyonu olan rand'ı kullanacağız, dağılım için de mod operatörünü kullanacağız.
Ardından aynı kodu C++ dilinde derleyip, rastgele sayı üreticisini ve dağılım kodunu standart kütüphane ile kullanacağız.

İkisinin de kalitesi aynı olsaydı, hesapladığımız olasılık değeri birbirine çok yakın olurdu.

Ayrıca zarda 7'nin gelme olasılığı, örneğin 12'nin gelme olasılığından daha fazla.

6 6 -> 12
6 1 -> 7
5 2 -> 7
4 3 -> 7

Dolayısıyla matematiksel açıdan bu yanlış. -> return rand() % 11 + 2; // Olasılık doğru değil.

--------------

#include <stdio.h>
#include <stdlib.h>

#define NGAMES		1'000'000

int roll_dice(void)
{
	int dice_1 = rand() % 6 + 1;
	int dice_2 = rand() % 6 + 1;

	return dice_1 + dice_2;
}

//1 --> player wins
//0 --> player loses

int game_(int dice)
{
	int new_dice;

	for (;;) {
		new_dice = roll_dice();
		if (new_dice == dice)
			return 1;
		if (new_dice == 7)
			return 0;
	}
}

int game(void)
{
	int dice = roll_dice();

	switch (dice) {
	case 7:
	case 11: return 1;
	case 2:
	case 3:
	case 12: return 0;
	default: return game_(dice);
	}
}

int main()
{
	int win_count = 0;

	for (int i = 0; i < NGAMES; ++i) {
		win_count += game();
	}

	printf("Kazanma olasiligi = %f\n", (double)win_count / NGAMES);
}

--------------


Aynı kodu C++'da yazarken sadece zar atma fonksiyonunu mersenne twister algoritmasını kullanarak yazıyoruz.

int roll_dice(void)
{
	static std::mt19937 eng;
	static std::uniform_int_distribution<int> dist(1, 6);
	int dice_1 = dist(eng);
	int dice_2 = dist(eng);

	return dice_1 + dice_2;
}

Sonuçlar: 

C	-> Kazanma olasiligi = 0.492299
C++ -> Kazanma olasiligi = 0.492808

Ciddi bir fark var. Dolayısıyla doğru olan değer C++'ın ürettiği değer. C'deki rastgele sayı üreticisi iyi bir üretici değil. 
Biz zarı oluştururken uniform dağılım için rand % 6 + 1 kodu iyi derecede uniform dağıtmıyor.

--------------
--------------

Monte Carlo yöntemiyle Pi sayısının hesaplanması

Burada bir kare var, karenin içinden geçen bir daire ölçeği var.

Sürkeli kare içinde rastgele nokta alıyoruz. Doğası gereği, aldığımız noktaların bir kısmı daire çeyreğinde, bir kısmı daire çeyreğinde değil.

Noktanın daire çeyreğinin içinde olma olasığılının cevabı: bu tamamen dolsaydı, daire çeyreğinin alanının karenin alanına oranı olurdu.

Karenin kenar uzunluğu 1 olduğuna göre, dairenin de çapı 1. Daire çeyreğinin alanının oranının, karenin alanına oranı noktanın daire içinde olma olasığını verecek.

Dairenin alanı = pi * r * r 

Karenin alanına oranı = pi / 4'ü vermesi gerekiyor

Biz şimdi rastgele sayı üreticisini kullanarak, 1 milyon tane kare içerisinden nokta alsak ve bunların kaç tanesinin daire çeyreği içinde olduğunu saysak, içindeki nokta sayısı / nokta sayısı değerinin pi / 4'e yakınsaması gerekiyor. 

x ve y noktasının birim kare içinde olması için x kare + y karenin, karekökünün 1'den küçük ya da eşit olması gerekiyor.

#include <stdio.h>
#include <stdlib.h>

#define NPOINTS 100'000'000

int main()
{
	int inside_count = 0;
	for (int i = 0; i < NPOINTS; ++i) {
		double x = (double)rand() / RAND_MAX; //Çok kötü bir yöntem çünkü 32767 olduğundan dolayı bu ifade yer yürütüldüğünde 32767 tane rastgele sayı almış oluruz.
		double y = (double)rand() / RAND_MAX;
		if (x * x + y * y <= 1.) { //x ve y noktasının birim kare içinde olması için x kare + y karenin, karekökünün 1'den küçük ya da eşit olması gerekiyor.
			++inside_count;
		}
	}

	printf("Pi Sayisi %.12f\n", 4. * inside_count / NPOINTS);
}

--------------
--------------

ÖDEV:

İki oyuncu var. Birisi oyuncu, diğeri kasa. Her ikisinin de $100 var.

Oyuncu her para atmadan önce $10 vermek zorunda.
Oyuncu eğer arka arkaya iki tura atarsa, kasa oyuncuya $35 vermek zorunda. TT, TT
Oyuncu eğer arka arkaya üç yazı atarsa, kasa oyuncuya $65 vermek zorunda. YYY, YYY

Zar atma sırası geldiğinde, eğer elindeki para $10'dan az ise, oyuncu kaybedecek.
Oyuncu $35 veya $65 kazandığında, kasanın elinde bu kadar para yoksa, kasa kaybedecek.

Bizden istenilen bu oyunu mesela 10000 kez vey 1000000 kez oynatıp ve oyuncunun kazanma olasılığını hesaplayacağız.

--------------
--------------

Diziler (Arrays)

Data Structure (Veri Yapısı)

Bir çok program veriler üzerinde işlem yapıyor. Bu işlemlerin yapılması için verilerin bellekte tutulması tutulması, konumlandırılması gerekiyor.
O verileri, bellekte nasıl tutacağımız bilgisine veri yapısı deniliyor.

Neden bu konunu önemli, çünkü kullandığımız veri yapısı, verilerin bellekte tutulma organizasyonu verimi %100 etkiliyor.

Bir veri yapısı, verileri organize etmek, işlemek, onların değerlerini elde etmek, onları bellekte tutmak için özelliştirilmiş bir format.

Bir çok veri yapısı özel bir amaca uygun olsun diye oluşturuluyor, böylece uygun bir şekilde bu veriyle çalışsın.


DATA STRUCTURES (veri yapılardan bazıları)

Arrays
	Fixed Array
	Dynamic Array

Heap
	Max Heap
	Min Heap

Trees
	Binary Search Tree
	Cartesian Tree
	B-Tree
	Red-black Tree
	Avl Tree

Linked Lists
	Singly Linked Lists
	Doubly Linked Lists
	Circular Linked Lists
	Rotating Linked Lists

Graphs
Hash Table
Deque

--------------

Ne yapmak istediğimize bağlı olarak, biz duruma göre bu bilinen veri yapılardan birini kullanmalıyız.
Maalesef C dili küçük bir dil olduğu için, C dilini standart kütüphanesi bu veri yapılarını kullanmamız için bir modül desteklemiyor.

Ya bunların kodunu kendimiz yazacağız, ya da 3. parti bir kütüphane kullanacağız.

--------------

Algoritma, bir işi gerçekleştirmek için ne yapılacak, hangi sırayla yapılacağının bilgisi.

Reverse Algortiması: Veri yapısındaki öğeleri ters çevirme.

Veri yapısındaki öğe sayısının yarısı kadar dönen bir döngüde, veri yapısındaki ilk öğe ile son öğeyi, ikinci öğe ile sondan ikinci öğeyi takas edeceğiz.

Veri yapısındaki öğe sayısı / 2 kez bunu yaptığımızda, veri yapısı reverse edilmiş olacak.

Kısacası veri yapısı, verilerin bellekte nasıl tutulduğu, nasıl organize edildiği bilgisi.
Algoritma da, bir işin nasıl yapıldığı bilgisi. Bu ikisi çok yakın ilişkide. Çünkü algoritmalar, veri yapıları üzerinde çalıştırılacak.

Algortimalarla ilgili önemli terimlerden de biri algoritma analizi. Algoritma analizi, algoritmayı ölçmeye, değerlendirmeye yönelik çalışmalara deniliyor.
Algoritma analizinde, algoritmanın verimliliğini ve başka algoritmalarla karşılaştırılmasını sağlayacak, bilgiler üretiliyor.

Mesela bir işi yapmak için ben bir algoritma öneriyorum, başkası bir algoritma öneriyor. Şimdi biz bunları analiz edeceğiz hangisi daha iyi.
Burada tipik olarak iki tane kaynak ve bu iki kaynağın yönetimi var. 

Birincisi, yapılan işlem sayısı. O işi gerçekleştirmek için ne kadar fazla işlem yapılırsa, o kadar zaman alacak.
İkinicisi ise, kullanılan bellek alanı. Mesela bellek alanı sıkıntım var, algoritmalardan biri diğerine göre 10 kat 100 kat 1000 kat daha fazla bellek alanı kullanıyor olabilir.

Algoritma analizi ile belirlemek istediğimiz değer, elde etmek istediğimiz bilgi, algoritmanın verimi ve algoritmanın çalıştırılması durumunda ihtiyaç duyulan bellek alanı.

Bunları ifade etmek için kullanılan bazı notasyonlar var. Bu notasyonlardan en sık kullanılalı Büyük O Gösterimi - Big O Notation.

Burada devreye algoritmanın karmaşıklığı terimi de devreye giriyor. Complexity of Algorithm

Bu da kendi içerisinde ikiye ayrılıyor.

time complexity		-> zamansal karmaşıklık
space complexity	-> bellek alan açısından karmaşıklık

time complexity	- zamansal karmaşıklık

https://cdn-media-1.freecodecamp.org/images/1*HwLR-DKk0lYNEMpkH475kg.png

(Grafikde veri yapısındaki öğe sayıları alt kısımda, maliyet de sol kısımda görünüyor.)

Burada ölçülen, veri yapısındaki öğe sayısının artmasıyla, yapılan işlem sayısının artması arasındaki ilişki.
Veri yapısındaki öğe sayısıyla, işlemin maliyeti arasındaki ilişki. Bu ilişki aslında algoritmanın verimini gösteriyor

Eğer yapılan işlem sayısı arttıkça, maliyet hiç artmıyorsa böyle karmaşıklığa sabit zaman karmaşıklığı deniliyor.
Yani veri yapısındaki öğe sayısı ne kadar artarsa artsın, bizim maliyetimiz sabit.

Bir başka karmaşıklık seviyesi, doğrusal - lineer karmaşıklık. Veri yapısındaki öğe sayısı arttıkça, maliyet de doğru orantılı olarak artıyor.

Maliyet, veri yapısındaki öğe sayısının karesiyle doğru ortantılı olabilir.
Maliyet, veri yapısındaki öğe sayısının kübüyle doğru ortantılı olabilir.
Maliyet, veri yapısındaki öğe sayısının 2 üzeri katsayısıyla doğru ortantılı olabilir. (10 tane öğe varken maliyet 2 üzeri 10, 20 tane öğe varken 2 üzeri 20 gibi)

Bu karmaşıklık seviyelerini göstermeye yönelik notasyonlardan en önemlisi, en sık kullanılalı Big O Notation.

Big O denmesinin sebebi, bu karmaşıklık seviyelerinin, büyük harf O karakterinden sonra gelen parantez içine yazılan ifadelerle temsil edilmesi.

O(1)		-> Constant Time. Veri yapısındaki öğe sayısı ne kadar artarsa artsın, maliyet hep aynı.
O(log n)	-> Logaritmic Complexity. Maliyet, 2 tabanından logaritma ile artıyor. Örneğin 1024 veri için 10 işlem yapıyorum, ama 2048 olduğunda çıktığında, ben sadece bir işlem daha yapıyorum.
O(n)		-> Linear Complexity. Veri yapısındaki öğe sayısıyla maliyet doğru orantılı. Öğe sayısı ne kadar artarsa, maliyet de o kadar artar.
O(n logn)	-> Linearitmic Complexity. Örneğin veri yapısında 64 öğe varsa, 64 * 2 tabanından 64 ün logaritması. Ama 1024se, 1024 * 2 tabanından 1024 ün logaritması.
O(n2)		-> Quadratic Complexity. Maliyet, veri yapısındaki öğe sayısının karesiyle doğru orantılı.
O(n3)
O(2^n)
O(n!)

*/