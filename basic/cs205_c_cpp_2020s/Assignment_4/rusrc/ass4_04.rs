use lib::ass4_03::ass4 as ass4_03;
use lib::ass4_04::ass4 as ass4_04;

mod lib;

fn main() {
    let m = ass4_03::question3();
    ass4_04::question4(&m);
}