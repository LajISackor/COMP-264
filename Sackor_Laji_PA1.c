#include <stdio.h>
#include <math.h>

// Function to calculate the mean of an array of floats
float mean(float arr[], int size) {
    float sum = 0.0;  // Variable to store the sum of all elements
    for (int i = 0; i < size; i++) {  // Loop through the array
        sum += arr[i];  // Add each element to the sum
    }
    // Return the mean value, rounded to 3 decimal places
    return roundf((sum / size) * 1000) / 1000;
}

// Function to calculate the median of an array of floats
float median(float arr[], int size) {
    // First, sort the array using bubble sort (not the most efficient, but simple)
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {  // Swap if elements are in the wrong order
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    // If the size is even, return the average of the middle two elements
    if (size % 2 == 0) {
        return roundf(((arr[size / 2 - 1] + arr[size / 2]) / 2) * 1000) / 1000;
    } else {
        // If the size is odd, return the middle element
        return roundf(arr[size / 2] * 1000) / 1000;
    }
}

// Function to calculate the mode of an array of floats
float mode(float arr[], int size) {
    int maxCount = 0;  // Variable to store the maximum frequency of any element
    float mode = -1;   // Default mode value, in case no mode is found (as per requirements)
    
    // Loop through the array to find the frequency of each element
    for (int i = 0; i < size; i++) {
        int count = 0;  // Variable to count occurrences of each element
        for (int j = 0; j < size; j++) {
            if (arr[j] == arr[i]) {
                count++;  // Increment count if a match is found
            }
        }
        // If the current element has a higher frequency than previous elements, update mode
        if (count > maxCount) {
            maxCount = count;
            mode = arr[i];
        }
    }
    
    // If the highest frequency is 1, there is no mode, so return -1
    if (maxCount == 1) {
        return -1;
    }
    
    return mode;
}

// Function to calculate the standard deviation of an array of floats
float std_dev(float arr[], int size) {
    float mean_value = mean(arr, size);  // Calculate the mean of the array
    float variance = 0.0;  // Variable to store the sum of squared deviations from the mean
    
    // Loop through the array and calculate each squared deviation
    for (int i = 0; i < size; i++) {
        variance += pow(arr[i] - mean_value, 2);  // Add the squared deviation to the variance
    }
    
    // Calculate the sample variance by dividing by (n-1), and then take the square root
    variance /= (size - 1);
    
    // Return the standard deviation, rounded to 3 decimal places
    return roundf(sqrt(variance) * 1000) / 1000;
}

// Function to round the floating-point values to integers
int* rounded_vals(float arr[], int size) {
    static int rounded[100];  // Static array to store the rounded values (assuming max size of 100)
    for (int i = 0; i < size; i++) {  // Loop through the array
        rounded[i] = roundf(arr[i]);  // Round each float to the nearest integer
    }
    return rounded;  // Return the pointer to the rounded integer array
}

// Function to convert integers to ASCII characters
char* ascii(int arr[], int size) {
    static char ascii_arr[100];  // Static array to store ASCII characters (assuming max size of 100)
    
    // Loop through the array of integers and convert them to ASCII
    for (int i = 0; i < size; i++) {
        // Check if the integer corresponds to a valid ASCII character (between 32 and 126)
        if (arr[i] >= 32 && arr[i] <= 126) {
            ascii_arr[i] = (char) arr[i];  // Convert integer to corresponding ASCII character
        } else {
            ascii_arr[i] = '*';  // If not a valid ASCII value, store '*' as a placeholder
        }
    }
    
    return ascii_arr;  // Return the pointer to the ASCII character array
}

// Function to print an array of characters to the console
void print_arr(char arr[], int size) {
    // Loop through the array and print each character
    for (int i = 0; i < size; i++) {
        printf("%c ", arr[i]);  // Print each character followed by a space
    }
    printf("\n");  // Print a new line after all characters are printed
}

// Main function to handle command-line input and call the other functions
int main(int argc, char *argv[]) {
    // Check if the user provided enough input (at least 2 numbers)
    if (argc < 3) {
        printf("Error: Provide at least two numbers as input.\n");
        return 1;  // Exit with an error code
    }
    
    // The size of the array is equal to the number of arguments (excluding the program name)
    int size = argc - 1;
    float arr[100];  // Static array to store the floating-point values (assuming max size of 100)
    
    // Convert the command-line arguments from strings to floats and store them in the array
    for (int i = 1; i < argc; i++) {
        arr[i - 1] = atof(argv[i]);
    }
    
    // Call the mean function and print the result
    printf("Mean: %.3f\n", mean(arr, size));
    
    // Call the median function and print the result
    printf("Median: %.3f\n", median(arr, size));
    
    // Call the mode function and print the result
    printf("Mode: %.3f\n", mode(arr, size));
    
    // Call the standard deviation function and print the result
    printf("Standard Deviation: %.3f\n", std_dev(arr, size));
    
    // Call the rounded_vals function and store the result
    int *rounded = rounded_vals(arr, size);
    
    // Print the rounded integer values
    printf("Rounded Values: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", rounded[i]);
    }
    printf("\n");
    
    // Call the ascii function and store the result
    char *ascii_arr = ascii(rounded, size);
    
    // Print the ASCII characters
    printf("ASCII Characters: ");
    print_arr(ascii_arr, size);
    
    return 0;  // Exit the program
}
