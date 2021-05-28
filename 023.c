/*

Ders23

Sıralama kriteri öğelerin sıralama işleminden sonra nasıl bir düzenle konumlandırılacağını açıklıyor. Küçükten büyüğe gibi.

Sıralama algoritması ise hangi basamakta neler yapılacak nerede döngü olacak nerede swap yapılacak onları anlatıyor.

Sıralama algoritmalarının tipik olarak karmaşıklık seviyesi O(nlogn) veya O(n^2) olabiliyor.

Time Complexity
Space Complexity

Bubble Sort Algoritması - Kabarcık Sıralaması Algoritması

Bu algoritmada su kabarcıkların dipten yüzeye yükselmesi gibi döngüsel bir yapı içerisinde dizinin elemanları sıralama kriteri neyse yerini alıyor.

188 252 231 748 529 485 841 674 752 940

Ardışık iki tane elemanı doğru yerde mi sorgulamasına sokuyoruz, bu elemanlar sıralama ilişkisine göre doğru yerdeyse, bunlara dokunmuyoruz ama yanlış yerdeyse bunları takas ediyoruz.

Örneğin küçükten büyüğe sıralama yapılacaksa;

[188 252] [231 748] [529 485] [841 674] [752 940]

188 252 231 748 485 529 674 841 752 940

Dizinin n tane öğesi varsa, dizinin n tane öğesini konumlandırmak için n - 1 tane karşılaştırma yapmak gerekir.

O zaman n - 1 tane öğeyi konumlandırmak için n - 1 * n - 1 kez dönen döngüye ihtiyacımız var. O(n) karmaşıklığı.

Örnek bubble sort implementasyonu - küçükten büğüye sıralama - O(n^2) karmaşıklığı

//Dıştaki döngü SIZE - 1 kez dönüyor çünkü SIZE - 1 öğeyi yerine koyarsak, geriye kalan öğe de mecbur yerine gelmiş olacak

//Dıştaki döngünün her turundan sonra içteki döngü 1 eksik dönebilir, o yüzden döngünün koşul ifadesini SIZE - 1 - i biçiminde yapıyoruz.

#include <stdio.h>
#include "dutility.h"

#define SIZE 10

int main()
{
	int a[SIZE];

	randomize();
	set_random_array(a, SIZE);
	print_array(a, SIZE);

	//kucukten buyuge siralama
	for (int i = 0; i < SIZE - 1; ++i) {
		for (int k = 0; k < SIZE - 1 - i; ++k) {
			if (a[k] > a[k + 1]) {
				int temp = a[k];
				a[k] = a[k + 1];
				a[k + 1] = temp;
			}
		}
	}

	print_array(a, SIZE);
}

---------------------------------------

Eğer sıralama kriteri if parantezi içine yazdığımız ifadeyle temsil ediliyorsa, 
buraya öyle bir ifade yazınız ki, bu dizi sıralandığında tekler başta, çiftler sonda olsun 
Ve tekler kendi içinde küçükten büyüğe sıralı, ve çiftler kendi içinde küçükten büyüğe sıralı olsun.

Algoritma değişmeyecek sadece if parantezi içindeki ifade değişecek.

Hangi koşulda swap yapmalıyız.

a[k] çift ise a[k + 1] tek ise 
a[k] ve a[k + 1] bunların oddity'si aynıysa ve a[k], a[k + 1]'den büyükse.

Örneğin 23 13. İkisi de tek. Küçük olan tek, büyük olan tekden daha önce gelmeli. Swap yapmalıyım.
Örneğin 38 26. İkisi de çift. Küçük olan çift, büyük olan çiftden daha önce gelmeli. Swap yapmalıyım.

#include <stdio.h>
#include "dutility.h"

#define SIZE 10

int main()
{
	int a[SIZE];

	randomize();
	set_random_array(a, SIZE);
	print_array(a, SIZE);

	//kucukten buyuge siralama
	for (int i = 0; i < SIZE - 1; ++i) {
		for (int k = 0; k < SIZE - 1 - i; ++k) {
			if ((a[k] % 2 == 0 && a[k + 1] % 2 != 0) || (a[k] % 2 == a[k + 1] % 2) && (a[k] > a[k + 1])) {
				int temp = a[k];
				a[k] = a[k + 1];
				a[k + 1] = temp;
			}
		}
	}
	print_array(a, SIZE);
}

---------------------------------------

Bubblesort algoritmasının karmaşıklığı O(n^2). Quicksort algoritmasının karmaşıklığı O(nlogn).

Şimdi bir diziyi, hem bubblesort algoritmasıyla hem de quicksort algoritmasıyla sıralayacağız ve sürelerini ölçeceğiz.

Dizinin boyutunu 100000 ayarlıyoruz fakat burada stack'de yani otomatik ömürlü nesneler için ayrılan bellek alanında, 100bin 200bin 1milyon elemanlı dizi oluşturma şansımız yok.
Bundan dolayı diziyi dinamik olarak oluşturuyoruz. Yani yerini runtime'da elde ediyoruz. Bu durumda dizimiz Heap dediğimiz bellek alanında oluşturulacak.

İlk olarak SIZE elemanlı bir diziye, malloc fonksiyonuyla programın çalışma zamanında bir yer ayırıyoruz.

Bubblesort algoritması = 100.000 Elemanı Dizi -> Siralama bitti! 10.142000 saniye

1 milyon öğesi olsaydı, 100binden 1milyona çıkması 10 kat artması demek, birebir O(n2) olsa c sabiti 1 olsa, 10 kat arttığına göre 1milyon elemanda 100 kat artacak.

100 * 10(100.000 eleman süresi) = 1000 Saniye 

5 milyon öğe olsaydı, bu 50 katına çıkacaktı. 50'nin karesi 2500. 2500 * 10 = 25000 Saniye

Bubblesort Kodu:

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dutility.h"

#define SIZE 100'000

int main()
{
	int* p = (int*)malloc(SIZE * sizeof(int));
	if (!p) {
		fprintf(stderr, "Bellek yetersiz!\n");
		return 1;
	}

	set_random_array(p, SIZE);

	printf("Siralama basladi!\n");

	clock_t start = clock();

	for (int i = 0; i < SIZE - 1; ++i) {
		for (int k = 0; k < SIZE - 1 - i; ++k) {
			if (p[k] > p[k + 1]) {
				int temp = p[k];
				p[k] = p[k + 1];
				p[k + 1] = temp;
			}
		}
	}

	clock_t end = clock();

	printf("Siralama bitti! %f saniye\n", (double)(end - start) / CLOCKS_PER_SEC);
	getchar();
}

---------------------------------------

Quicksort Kodu:

Standart kütüphanenin zaten bu işi yapan stdlib.h başlık dosyasında bildirilen qsort isimli fonksiyon var.

Bubblesort algoritması = 100.000 Elemanı Dizi -> Siralama bitti! 10.142000 saniye

Quicksort algoritması = 100.000 Elemanı Dizi -> Siralama bitti! 0.006000 saniye

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dutility.h"

#define SIZE 5'000'000

int icmp(const void* vp1, const void* vp2)
{
	return *(const int*)vp1 - *(const int*)vp2;
}

int main()
{
	int* p = (int*)malloc(SIZE * sizeof(int));
	if (!p) {
		fprintf(stderr, "Bellek yetersiz!\n");
		return 1;
	}

	set_random_array(p, SIZE);

	printf("Siralama basladi!\n");

	clock_t start = clock();

	qsort(p, SIZE, sizeof(*p), icmp);

	clock_t end = clock();

	printf("Siralama bitti! %f saniye\n", (double)(end - start) / CLOCKS_PER_SEC);
	getchar();
}

---------------------------------------

icmp fonksiyonu nedir? Bu tür fonksiyonlara callback functions deniliyor. 
qsort fonksiyonu dizinin elemanlarının türlerini bilmediği için, karşılaştırmanın nasıl yapılacağı bilgisini kendisini çağıran koddan alıyor.
bir fonksiyonu, bir fonksiyona argüman olarak gönderiyoruz.

qsort, bizim dizimizin elemanlarını karşılaştırmak için bizim sana adresini gönderdiğimiz fonksiyonu çağıracaksın.

Bir fonksiyona bir fonksiyonu argüman olarak gönderme yapısına callback deniliyor.

---------------------------------------

Dizinin unique olan elemanlarının bulunması:

Birincisi O(n^2) karmaşıklığı olduğu kesin. İç içe iki tane döngü olacak.

#include <stdio.h>
#include <stdlib.h>
#include "dutility.h"

#define SIZE 20

int main()
{
	int a[SIZE];

	randomize();

	for (int i = 0; i < SIZE; ++i) {
		a[i] = rand() % 20; //0 - 20 aralığında değer atıyoruz rastgele.
	}

	print_array(a, SIZE);

	int i, k;

	for (i = 0; i < SIZE; ++i) {
		for (k = 0; k < SIZE; ++k) {
			if (i != k && a[i] == a[k]) // a[i] -> unique değil. eğer içteki döngüden break deyimi ile çıkmışsak, a[i] unique değil. ama break ile değil de, k'nın SIZE'dan küçük olmasından dolayı çıkmışsak, o zaman kesinlikle a[i] unique.
				break;
		}

		if (k == SIZE)
			printf("%3d ", a[i]);
	}
}

---------------------------------------

O(n) karmaşıklığında unique elemanları bulma.

#include <stdio.h>
#include <stdlib.h>
#include "dutility.h"

#define SIZE 20

int main()
{
	int a[SIZE];
	int cnt[20] = { 0 }; // cnt dizisi 0 - 19 arasındaki değerlerden her birinden kaç tane var, bu değeri tutacak.
						// örnek olarak, cnt dizisinin 0 indisli elemanı, a dizisinde kaç tane 0 var, bu değeri tutacak gibi.
	randomize();

	for (int i = 0; i < SIZE; ++i) {
		a[i] = rand() % 20;
	}

	print_array(a, SIZE);

	for (int i = 0; i < SIZE; ++i) {
		++cnt[a[i]]; // cnt dizisinin, a[i] elemanının değerini, 1 arttırıyoruz.
	}

	//Bu döngüden sonra, cnt dizisine bakarsak, örneğin cnt dizisinin 5 indisli elemanı eğer 1 ise, dizide 1 tane 5 elemanı var demek.
	//Bu döngüden sonra, cnt dizisine bakarsak, örneğin cnt dizisinin 5 indisli elemanı eğer 3 ise, dizide 3 tane 5 elemanı var demek.

	//Şimdi cnt dizisinin elemanlarını dolaşıyoruz.

	for (int i = 0; i < 20; ++i) {
		if (cnt[i] == 1)
			printf("%3d ", i);
	}

	//Böylece yardımcı bir dizi kullanarak, değerlerinde sadece belirli aralıkta olmasından faydalanarak unique olanları küçükten büyüğe yazdırdık.
}

---------------------------------------

ÖDEV:

Bir tane dizimiz var. Bu dizinin en az bir elemanı negatif değerde. Birden fazla negatif değer de olabilir.

int a[] = {12, -5, 34, -45, 5, 90, 23, 45};

sub-sequence
ardışık alt dizi

Bir dizinin

*/

