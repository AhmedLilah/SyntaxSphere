package com.perftest;

import java.util.Arrays;
import java.util.concurrent.TimeUnit;

public class IndexingPerformanceTest {
    private static final int NUM_OF_VARS = 20;
    private static final int VAR_LEN = (int) 1e6;
    private static final int[] NUM_OF_WEIGHTS = RandUtility.rndIntArray(0, 4, NUM_OF_VARS);
    private static final int NUM_OF_WEIGHTS_SUM = Arrays.stream(NUM_OF_WEIGHTS).sum();
    private static final int[] PREFIX_SUM_ARRAY = fillPrefixSum();
    private static final int NUM_OF_ITERATIONS = 10000;
    private static long normalTimeTotalAllVars = 0;
    private static long interleavedTimeTotalAllVars = 0;
    private static long normalTimeTotalOneVar = 0;
    private static long interleavedTimeTotalOneVar = 0;

    private static float[][] luts;
    private static float[] bigLut;


    private static int[] fillPrefixSum() {
        int[] prefixSum = new int[IndexingPerformanceTest.NUM_OF_WEIGHTS.length];
        prefixSum[0] = 0;
        for (int i = 1; i < IndexingPerformanceTest.NUM_OF_WEIGHTS.length; ++i)
            prefixSum[i] = prefixSum[i - 1] + IndexingPerformanceTest.NUM_OF_WEIGHTS[i-1];
        return prefixSum;
    }


    public static void generateLuts() {
        luts = new float[NUM_OF_VARS][];
        for (int i = 0; i < NUM_OF_VARS; i++) {
            luts[i] = RandUtility.rndFloatArray(1e-6f, 1, VAR_LEN * NUM_OF_WEIGHTS[i]);
        }
        bigLut = new float[VAR_LEN * NUM_OF_WEIGHTS_SUM];
        for (int elementIndex = 0; elementIndex < VAR_LEN; elementIndex++) {
            for (int currVarIndex = 0; currVarIndex < NUM_OF_VARS; currVarIndex++) {
                for (int weightIndex = 0; weightIndex < NUM_OF_WEIGHTS[currVarIndex]; weightIndex++) {
                    int bigLutRealIndex = (elementIndex * NUM_OF_WEIGHTS_SUM) + PREFIX_SUM_ARRAY[currVarIndex] + weightIndex;
                    int smallLutRealIndex = elementIndex * NUM_OF_WEIGHTS[currVarIndex] + weightIndex;
                    bigLut[bigLutRealIndex] = luts[currVarIndex][smallLutRealIndex];
                }
            }
        }
    }

    public static float[] getAllOutputsSameIndexNormalMethod(int currRandIndex) {
        float[] myQueryArray = new float[NUM_OF_WEIGHTS_SUM];
        for (int currVarIndex = 0; currVarIndex < NUM_OF_VARS; currVarIndex++) {
            for (int currWeightIndex = 0; currWeightIndex < NUM_OF_WEIGHTS[currVarIndex]; currWeightIndex++) {
                int myQueryRealIndex = PREFIX_SUM_ARRAY[currVarIndex] + currWeightIndex;
                int smallLutRealIndex = (currRandIndex * NUM_OF_WEIGHTS[currVarIndex]) + currWeightIndex;
                myQueryArray[myQueryRealIndex] = luts[currVarIndex][smallLutRealIndex];
            }
        }
        return myQueryArray;
    }

    public static float[] getAllOutputsSameIndexInterleaved(int currRandIndex) {
        return Arrays.copyOfRange(bigLut, currRandIndex * NUM_OF_WEIGHTS_SUM, currRandIndex * NUM_OF_WEIGHTS_SUM + NUM_OF_WEIGHTS_SUM);
    }


    public static float[] getOneVariableNormalMethod(int currRandIndex) {
        float[] myQueryArray = new float[luts[currRandIndex].length];
        for (int i = 0; i < luts[currRandIndex].length; i++) {
            myQueryArray[i] = luts[currRandIndex][i];
        }
        return myQueryArray;
    }

    public static float[] getOneVariableInterleaved(int currRandIndex) {
        float[] myQueryArray = new float[VAR_LEN * NUM_OF_WEIGHTS[currRandIndex]];

        for (int currIndex = 0; currIndex < VAR_LEN; currIndex++) {
            for (int currWeightIndex = 0; currWeightIndex < NUM_OF_WEIGHTS[currRandIndex]; currWeightIndex++) {
                int myQueryIndex = (currIndex * NUM_OF_WEIGHTS[currRandIndex]) + currWeightIndex;
                int bigLutIndex = (currIndex * NUM_OF_WEIGHTS_SUM) + PREFIX_SUM_ARRAY[currRandIndex] + currWeightIndex;
                myQueryArray[myQueryIndex] = bigLut[bigLutIndex];
            }
        }
        return myQueryArray;
    }

    public static void assertCorrectness(float[] myQueryArray1, float[] myQueryArray2) {
        if (!Arrays.equals(myQueryArray1, myQueryArray2)) {
            throw new RuntimeException("ARRAYS ARE NOT EQUAL");
        }
    }

    public static void consumeOutputs(float[] myQueryArray1, float[] myQueryArray2) {

    }

    public static void main(String[] args) {
        long totalTimeStart = System.nanoTime();
        int randomIndexAllVars;
        int randomIndexOneVar;
        float[] myQueryAllVars1;
        float[] myQueryAllVars2;
        float[] myQueryOneVars1;
        float[] myQueryOneVars2;
        long assertTimeTotal = 0;

        long generateLutsTimeStart = System.nanoTime();
        generateLuts();
        long generateLutsTimeEnd = System.nanoTime();
        long generateLutsTimeTotal = generateLutsTimeEnd - generateLutsTimeStart;
        System.out.printf("Generating LUTs time taken in ms = %s%n", TimeUnit.NANOSECONDS.toMillis(generateLutsTimeTotal));


        long loopTimeStart = System.nanoTime();

        for (int i = 0; i < NUM_OF_ITERATIONS; i++) {

//            if (i % 100000 == 0 && i != 0) {
//                generateLuts();
//            }

            randomIndexAllVars = RandUtility.nextIntBetween(0, VAR_LEN);


            long normalTimeStart = System.nanoTime();
            myQueryAllVars1 = getAllOutputsSameIndexNormalMethod(randomIndexAllVars);
            long normalTimeEnd = System.nanoTime();
            normalTimeTotalAllVars += normalTimeEnd - normalTimeStart;


            long interleavedTimeStart = System.nanoTime();
            myQueryAllVars2 = getAllOutputsSameIndexInterleaved(randomIndexAllVars);
            long interleavedTimeEnd = System.nanoTime();
            interleavedTimeTotalAllVars += interleavedTimeEnd - interleavedTimeStart;

//            long assertCorrectnessStart = System.nanoTime();
//            assertCorrectness(myQueryAllVars1, myQueryAllVars2);
            consumeOutputs(myQueryAllVars1, myQueryAllVars2);
//            long assertCorrectnessEnd = System.nanoTime();
//            assertTimeTotal += assertCorrectnessEnd - assertCorrectnessStart;

            randomIndexOneVar = RandUtility.nextIntBetween(0, NUM_OF_VARS);
            long normalTimeStartOneVar = System.nanoTime();
            myQueryOneVars1 = getOneVariableNormalMethod(randomIndexOneVar);
            long normalTimeEndOneVar = System.nanoTime();
            normalTimeTotalOneVar += normalTimeEndOneVar - normalTimeStartOneVar;


            long interleavedTimeStartOneVar = System.nanoTime();
            myQueryOneVars2 = getOneVariableInterleaved(randomIndexOneVar);
            long interleavedTimeEndOneVar = System.nanoTime();
            interleavedTimeTotalOneVar += interleavedTimeEndOneVar - interleavedTimeStartOneVar;

//            assertCorrectnessStart = System.nanoTime();
//            assertCorrectness(myQueryOneVars1, myQueryOneVars2);
//            assertCorrectnessEnd = System.nanoTime();
            consumeOutputs(myQueryOneVars1, myQueryOneVars2);
//            assertTimeTotal += assertCorrectnessEnd - assertCorrectnessStart;
        }


        long loopTimeEnd = System.nanoTime();
        long loopTimeTotal = loopTimeEnd - loopTimeStart;
        System.out.printf("Loop time in ms = %s%n", TimeUnit.NANOSECONDS.toMillis(loopTimeTotal));

        System.out.printf("TOTAL NUMBER OF WEIGHTS = %s%n", NUM_OF_WEIGHTS_SUM);

        double avgNormal = (double) normalTimeTotalAllVars / NUM_OF_ITERATIONS;
        double avgInterleaved = (double) interleavedTimeTotalAllVars / NUM_OF_ITERATIONS;

        System.out.println("===========================GETTING ALL VARS AT A SPECIFIC INDEX===========================");
        System.out.printf("Normal method: Total time taken in ms = %s%n", TimeUnit.NANOSECONDS.toMillis(normalTimeTotalAllVars));
        System.out.printf("Normal method: Average time per iteration in ns = %s%n", avgNormal);
        System.out.printf("Interleaved method: Total time taken in ms = %s%n", TimeUnit.NANOSECONDS.toMillis(interleavedTimeTotalAllVars));
        System.out.printf("Interleaved method: Average time per iteration in ns = %s%n", avgInterleaved);
        System.out.printf("Speedup in total time = %sx%n", (double) normalTimeTotalAllVars / interleavedTimeTotalAllVars);
        System.out.printf("Speedup in average time = %sx%n", avgNormal / avgInterleaved);


        double avgNormalOne = (double) normalTimeTotalOneVar / NUM_OF_ITERATIONS;
        double avgInterleavedOne = (double) interleavedTimeTotalOneVar / NUM_OF_ITERATIONS;

        System.out.println("===========================GETTING ALL OF ONE VAR===========================");
        System.out.printf("Normal method: Total time taken in ms = %s%n", TimeUnit.NANOSECONDS.toMillis(normalTimeTotalOneVar));
        System.out.printf("Normal method: Average time per iteration in ns = %s%n", avgNormalOne);
        System.out.printf("Interleaved method: Total time taken in ms = %s%n", TimeUnit.NANOSECONDS.toMillis(interleavedTimeTotalOneVar));
        System.out.printf("Interleaved method: Average time per iteration in ns = %s%n", avgInterleavedOne);
        System.out.printf("Slowdown in total time = %sx%n", (double) interleavedTimeTotalOneVar / normalTimeTotalOneVar);
        System.out.printf("Slowdown in average time = %sx%n", avgInterleavedOne / avgNormalOne);
        long totalTimeEnd = System.nanoTime();
        long totalTime = totalTimeEnd - totalTimeStart;
        System.out.printf("Assert time in ms = %s%n", TimeUnit.NANOSECONDS.toMillis(assertTimeTotal));
        System.out.printf("Total test time in ms = %s%n", TimeUnit.NANOSECONDS.toMillis(totalTime));

    }
}
