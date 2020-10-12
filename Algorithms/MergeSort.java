import java.util.Random;

/**
 * Merge Sort implementation in Java
 * @author juanmagutierrez
 */
public class MergeSort {
    
    /**
     * This method sorts given array by spliting it in halves and merging them into an ordered array
     * @param array
     * @return ordered array
     */
    public static int[] merge_sort(int[] array) {
    
        // Base case: an array of zero or one elements is always sorted
        if (array == null) {
            return null;
        } else if (array.length <= 1) { 
            return array;
        }

        //Recursive case: we need to split the array into two arrays (with similar size)
        double half_length = ((double) array.length)/2;
        int[] left_array = new int[(int) Math.floor(half_length)];
        int[] right_array = new int[(int) Math.ceil(half_length)];

        int left_array_index = 0;
        int righ_array_index = 0;

        for (int i=0; i < array.length; i++) {
            if (i < array.length/2 ) {
                left_array[left_array_index] = array[i];
                left_array_index++;
            } else {
                right_array[righ_array_index] = array[i];
                righ_array_index++;
            }
        }

        //Now we sort both arrays in a recursive way
        left_array = merge_sort(left_array);
        right_array = merge_sort(right_array);

        //Finally we merge both ordered arrays
        return merge_ordered_arrays(left_array, right_array);
    }
    
    /**
     * This method returns an ordered array of two ordered arrays given as parameters
     * @param left_array
     * @param right_array
     * @return ordered array with all the elements of left_array and right_array
     */
    public static int[] merge_ordered_arrays(int[] left_array, int [] right_array) {
         
        int[] ordered_array = new int[left_array.length + right_array.length];
        int ordered_array_index = 0;
        int left_array_index = 0;
        int right_array_index = 0;
        
        //While both arrays have elements we need to compare their indexes and select the lowest
        while (left_array_index < left_array.length && right_array_index < right_array.length) {
            if (left_array[left_array_index] <= right_array[right_array_index]) {
                ordered_array[ordered_array_index] = left_array[left_array_index];
                left_array_index++;         
            } else {
                ordered_array[ordered_array_index] = right_array[right_array_index];
                right_array_index++;
            }
            ordered_array_index++;
        }

        //Only one of both arrays may have elements left, so we have to put them into the ordered result array
        while (left_array_index < left_array.length) {
            ordered_array[ordered_array_index] = left_array[left_array_index];
            left_array_index++;         
            ordered_array_index++;
        }
        
        while (right_array_index < right_array.length) {
            ordered_array[ordered_array_index] = right_array[right_array_index];
            right_array_index++;
            ordered_array_index++;
        }
         
        return ordered_array;
    }
    
    /**
     * This method prints given array like elements separated by commas like:
     *              [1, 2, 3, 4, 5, 6, 7]
     * @param array
     * @return 
     */
    public static String array_to_string(int[] array) {
        if (array == null) {
            return "Null Array";
        }
        
        String array_str = "[";
        
        for (int i=0; i < array.length; i++) {
            if (i > 0) {
                array_str += ", ";
            }
            array_str += array[i];
        }
        array_str += "]";
        
        return array_str;
    }
    
    public static void main(String[] args) {
        
        //Test of merge sort algorithm with an array of 10 positive random numbers below 100
        int[] unordered_array = new int[10];
        Random random = new Random();
        
        for (int i=0; i < unordered_array.length; i++) {
            unordered_array[i] = Math.abs(random.nextInt() % 100);
        }
        
        System.out.println("-------Merge Sort algorithm test-------\n");
        
        System.out.println("Unordered array: ");
        System.out.println(array_to_string(unordered_array));
        
        int[] merge_sorted_array = merge_sort(unordered_array);
        
        System.out.println("\n");
        System.out.println("Merge sort result: ");
        System.out.println(array_to_string(merge_sorted_array));
        
        System.out.println("---------------------------------------\n");
    }
}