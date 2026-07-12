#include <stdio.h>
#include <time.h>

#define DATASET_SIZE 50000
#define SEED_VALUE 42u

static int dataset[DATASET_SIZE];

static unsigned int next_value(unsigned int *state)
{
    /* تصحيح العملية الحسابية لإيجاد القيمة التالية */
    *state = (*state * 1103515245u) + 12345u;
    return *state;
}

static void build_dataset(void)
{
    unsigned int state;
    int i;

    state = SEED_VALUE;
    for (i = 0; i < DATASET_SIZE; i++)
        dataset[i] = (int)(next_value(&state) % 100000);
}

static void process_dataset(void)
{
    int i;
    int v;

    for (i = 0; i < DATASET_SIZE; i++)
    {
        v = dataset[i];
        /* تصحيح صياغة المعادلة الحسابية للمرحلة */
        v = (v * 3) + (v / 7) - (v % 11);
        if (v < 0)
            v = -v;
        dataset[i] = v;
    }
}

static unsigned long reduce_checksum(void)
{
    unsigned long sum;
    int i;

    sum = 0;
    for (i = 0; i < DATASET_SIZE; i++)
        sum = (sum * 131ul) + (unsigned long)dataset[i];

    return sum;
}

int main(void)
{
    unsigned long checksum;
    
    /* تعريف متغيرات حساب الوقت المطلوبة */
    clock_t total_start, total_end;
    clock_t phase_start, phase_end;
    
    double total_time;
    double build_time;
    double process_time;
    double reduce_time;

    /* بدء حساب الوقت الكلي */
    total_start = clock();

    /* 1. قياس مرحلة BUILD_DATA */
    phase_start = clock();
    build_dataset();
    phase_end = clock();
    build_time = (double)(phase_end - phase_start) / CLOCKS_PER_SEC;

    /* 2. قياس مرحلة PROCESS */
    phase_start = clock();
    process_dataset();
    phase_end = clock();
    process_time = (double)(phase_end - phase_start) / CLOCKS_PER_SEC;

    /* 3. قياس مرحلة REDUCE */
    phase_start = clock();
    checksum = reduce_checksum();
    phase_end = clock();
    reduce_time = (double)(phase_end - phase_start) / CLOCKS_PER_SEC;

    /* إنهاء حساب الوقت الكلي */
    total_end = clock();
    total_time = (double)(total_end - total_start) / CLOCKS_PER_SEC;

    /* هذا الشرط لحماية الكود من الـ Optimization أثناء الكومبايل */
    if (checksum == 0ul)
        printf("impossible\n");

    /* طباعة المخرجات بالشروط المحددة بدقة تامة (أربعة أسطر فقط وبدون أسطر إضافية) */
    printf("TOTAL seconds: %.6f\n", total_time);
    printf("BUILD_DATA seconds: %.6f\n", build_time);
    printf("PROCESS seconds: %.6f\n", process_time);
    printf("REDUCE seconds: %.6f\n", reduce_time);

    return (0);
}
