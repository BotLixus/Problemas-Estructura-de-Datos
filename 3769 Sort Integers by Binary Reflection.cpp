class Solution {
public:

    int reflejar(int numero) {
        int reflejo = 0;

        while (numero > 0) {
            reflejo = reflejo * 2 + numero % 2;
            numero = numero / 2;
        }

        return reflejo;
    }

    vector<int> sortByReflection(vector<int>& nums) {
        int cantidad = nums.size();

        for (int i = 0; i < cantidad - 1; i++) {
            for (int j = 0; j < cantidad - i - 1; j++) {

                int reflejoActual = reflejar(nums[j]);
                int reflejoSiguiente = reflejar(nums[j + 1]);

                if (reflejoActual > reflejoSiguiente ||
                    (reflejoActual == reflejoSiguiente && nums[j] > nums[j + 1])) {

                    int temporal = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temporal;
                }
            }
        }
