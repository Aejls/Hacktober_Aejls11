package algo.kadane;

public class KadanesAlgorithm {
    public static void main(String[] args) {
        KadanesAlgorithm maxSliceSum = new KadanesAlgorithm();
        System.out.println(maxSliceSum.solution(new int[] {3,2,-6,4,0}));
    }

    private int solution(int[] A) {
        int maxEndingHere = 0;
        int maxSoFar = 0;
        for(int a : A) {
            maxEndingHere = Math.max(a, maxEndingHere + a);
            maxSoFar = Math.max(maxSoFar, maxEndingHere);
        }
        return maxSoFar;
    }
}
