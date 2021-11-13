/*
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2021-06-22 16:21:51
 * @LastEditors: nanoseeds
 * @LastEditTime: 2021-06-24 20:32:44
 */
pub mod lab07_03 {
    pub fn fill_array(arr: &mut Vec<f64>) -> usize {
        for order in 0..arr.len() {
            println!("Enter value #{}:", (order + 1));
            let mut input_str = String::new();
            std::io::stdin().read_line(&mut input_str).expect("read fail");
            arr[order] = match input_str.trim().parse::<f64>() {
                Ok(num) => { num }
                Err(error) => {
                    println!("Input should Correct,default value is 0");
                    0f64
                }
            };
        }
        return 0;
    }

    pub fn show_array(arr: &Vec<f64>) {
        for num in arr.iter() {
            print!("{} ", num);
        }
        println!();
    }

    pub fn reverse_array(size: usize, arr: &mut [f64]) {
        if size == 0usize || size == 1usize {
            return;
        }
        let fst = arr.len() - size;
        let temp = arr[size - 1];
        arr[size - 1] = arr[fst];
        arr[fst] = temp;
        reverse_array(size - 2, arr);
    }
}