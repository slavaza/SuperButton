# SupeButton

Detects a single double and long press with the suppression of the bounce of the contacts. Does not require any additional resources of the microcontroller. Uses the system timer. Very easy to use.

Using
-----

See example for how to use the class.

#### constructor

`SuperButton::SuperButton(pin, guardtime, doubletime, longertime);` create and setup timing

#### constant

returns from SuperButoon::pressed() method as the event meaning

`SuperButton::Press::NO` event not detected
`SuperButton::Press::SINGLE` single pressing detected
`SuperButton::Press::DOUBLE` double pressing detected
`SuperButton::Press::LONGER` long pressing detected

#### method

`SuperButton::pressed()` returns enumerate value about detected event, need to periodically calling

You can install this library by the library manager Arduino also. 
