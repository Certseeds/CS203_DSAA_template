/*  CS205_C_CPP
    Copyright (C) 2020  nanoseeds

    CS205_C_CPP is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as
    published by the Free Software Foundation, either version 3 of the
    License, or (at your option) any later version.

    CS205_C_CPP is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
    */
use std::fmt;

pub struct Rectangle {
    pub width: f64,
    pub height: f64,
}

impl Rectangle {
    pub fn get_area(&self) -> f64 {
        self.width * self.height
    }
    pub fn get_perimeter(&self) -> f64 {
        2.0f64 * (self.width + self.height)
    }
    pub fn display(&self) {
        println!("{}", &self);
    }
}

impl fmt::Display for Rectangle {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        return write!(f, r#"    -------------
    Width:      {}
    Height:     {}
    Area:       {:5.3}
    Perimeter:  {:5.3}"#, self.width, self.height, self.get_area(), self.get_perimeter());
    }
}

