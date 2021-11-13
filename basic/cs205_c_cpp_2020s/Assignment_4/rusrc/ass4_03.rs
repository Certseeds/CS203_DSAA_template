use lib::ass4_02::ass4 as ass4_02;
use lib::ass4_03::ass4 as ass4_03;

mod lib;

fn main() {
    let m = ass4_03::question3();
    ass4_02::question2(&m);
}