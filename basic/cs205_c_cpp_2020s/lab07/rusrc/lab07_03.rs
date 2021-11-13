mod lib;

mod lab07_03 {
    use crate::lib::lab07_03::lab07_03;

    pub(crate) fn main() {
        let mut input_str = String::new();
        std::io::stdin().read_line(&mut input_str).expect("read fail");
        let size = match input_str.trim().parse::<usize>() {
            Ok(num) => { num }
            Err(error) => { 0 }
        };
        let mut array = vec![0f64; size];
        lab07_03::fill_array(&mut array);
        lab07_03::show_array(&array);
        lab07_03::reverse_array(array.len(), &mut array);
        lab07_03::show_array(&array);
        lab07_03::reverse_array(array.len() - 2, &mut array[1..(size - 1)]);
        lab07_03::show_array(&array);
    }
}

fn main() {
    lab07_03::main();
}