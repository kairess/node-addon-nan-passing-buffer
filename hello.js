var addon = require('bindings')('hello');

console.log(addon.hello(new Buffer.from('asdfasdf123asdfss한글도됨korean')).toString()); // 'world'