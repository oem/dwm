# $Id: PKGBUILD 60970 2011-12-19 21:33:58Z spupykin $
# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: Dag Odenhall <dag.odenhall@gmail.com>
# Contributor: Grigorios Bouzakis <grbzks@gmail.com>

pkgname=dwm
pkgver=6.0
pkgrel=1
pkgdesc="A dynamic window manager for X"
url="http://dwm.suckless.org"
arch=('i686' 'x86_64')
license=('MIT')
options=(zipman)
depends=('libx11' 'libxinerama')
install=dwm.install
source=(http://dl.suckless.org/dwm/dwm-$pkgver.tar.gz
	config.h
	dwm.desktop)
md5sums=('8bb00d4142259beb11e13473b81c0857'
         '2453e037f46449774ec8afab49b4f1a2'
         '939f403a71b6e85261d09fc3412269ee')

build() {
  cd $srcdir/$pkgname-$pkgver
  cp $srcdir/config.h config.h
  sed -i 's/CPPFLAGS =/CPPFLAGS +=/g' config.mk
  sed -i 's/^CFLAGS = -g/#CFLAGS += -g/g' config.mk
  sed -i 's/^#CFLAGS = -std/CFLAGS += -std/g' config.mk
  sed -i 's/^LDFLAGS = -g/#LDFLAGS += -g/g' config.mk
  sed -i 's/^#LDFLAGS = -s/LDFLAGS += -s/g' config.mk
  make X11INC=/usr/include/X11 X11LIB=/usr/lib/X11
}

package() {
  cd $srcdir/$pkgname-$pkgver
  make PREFIX=/usr DESTDIR=$pkgdir install
  install -m644 -D LICENSE $pkgdir/usr/share/licenses/$pkgname/LICENSE
  install -m644 -D README $pkgdir/usr/share/doc/$pkgname/README
  install -m644 -D $srcdir/dwm.desktop $pkgdir/usr/share/xsessions/dwm.desktop
}
md5sums=('8bb00d4142259beb11e13473b81c0857'
         '6c07c4d8c76bc2118e8ce203df524344'
         '939f403a71b6e85261d09fc3412269ee')
md5sums=('8bb00d4142259beb11e13473b81c0857'
         'ed834dcd3e228084db55a2a1d84f78c5'
         '939f403a71b6e85261d09fc3412269ee')
md5sums=('8bb00d4142259beb11e13473b81c0857'
         'c11a5439ffcb4d1a68d8a6a7065776ed'
         '939f403a71b6e85261d09fc3412269ee')
md5sums=('8bb00d4142259beb11e13473b81c0857'
         '6fe525816a725e8070b94794697547fb'
         '939f403a71b6e85261d09fc3412269ee')
md5sums=('8bb00d4142259beb11e13473b81c0857'
         '5011610e141f6fcd47522e0e1abe56f9'
         '939f403a71b6e85261d09fc3412269ee')
md5sums=('8bb00d4142259beb11e13473b81c0857'
         '6fe525816a725e8070b94794697547fb'
         '939f403a71b6e85261d09fc3412269ee')
md5sums=('8bb00d4142259beb11e13473b81c0857'
         '6fe525816a725e8070b94794697547fb'
         '939f403a71b6e85261d09fc3412269ee')
md5sums=('8bb00d4142259beb11e13473b81c0857'
         'a000d0526b1ad90e9a5253b21aa33cbc'
         '939f403a71b6e85261d09fc3412269ee')
md5sums=('8bb00d4142259beb11e13473b81c0857'
         'f844fefd3479f0490e29e30c679b854f'
         '939f403a71b6e85261d09fc3412269ee')
md5sums=('8bb00d4142259beb11e13473b81c0857'
         '4594914135d7de9752311fbd7fd2e95b'
         '939f403a71b6e85261d09fc3412269ee')
md5sums=('8bb00d4142259beb11e13473b81c0857'
         '47059e14e0cdd484d1646d5cd2363b4d'
         '939f403a71b6e85261d09fc3412269ee')
md5sums=('8bb00d4142259beb11e13473b81c0857'
         '2f98ad1b465619e9b7253f7b58444063'
         '939f403a71b6e85261d09fc3412269ee')
md5sums=('8bb00d4142259beb11e13473b81c0857'
         '2f98ad1b465619e9b7253f7b58444063'
         '939f403a71b6e85261d09fc3412269ee')
md5sums=('8bb00d4142259beb11e13473b81c0857'
         '2a58ef00e39df3975409159c9fc5bdfa'
         '939f403a71b6e85261d09fc3412269ee')
md5sums=('8bb00d4142259beb11e13473b81c0857'
         '4594914135d7de9752311fbd7fd2e95b'
         '939f403a71b6e85261d09fc3412269ee')
md5sums=('8bb00d4142259beb11e13473b81c0857'
         '2a58ef00e39df3975409159c9fc5bdfa'
         '939f403a71b6e85261d09fc3412269ee')
md5sums=('8bb00d4142259beb11e13473b81c0857'
         '2f98ad1b465619e9b7253f7b58444063'
         '939f403a71b6e85261d09fc3412269ee')
md5sums=('8bb00d4142259beb11e13473b81c0857'
         '2f98ad1b465619e9b7253f7b58444063'
         '939f403a71b6e85261d09fc3412269ee')
md5sums=('8bb00d4142259beb11e13473b81c0857'
         '18a57366ad43fc981cf0cce49ce2e497'
         '939f403a71b6e85261d09fc3412269ee')
md5sums=('8bb00d4142259beb11e13473b81c0857'
         '18a57366ad43fc981cf0cce49ce2e497'
         '939f403a71b6e85261d09fc3412269ee')
md5sums=('8bb00d4142259beb11e13473b81c0857'
         '03c821391bee9f5c762736b06a5819ca'
         '939f403a71b6e85261d09fc3412269ee')
md5sums=('8bb00d4142259beb11e13473b81c0857'
         '69457bd8dd067feb70527311c1f72e0c'
         '939f403a71b6e85261d09fc3412269ee')
md5sums=('8bb00d4142259beb11e13473b81c0857'
         '69457bd8dd067feb70527311c1f72e0c'
         '939f403a71b6e85261d09fc3412269ee')
md5sums=('8bb00d4142259beb11e13473b81c0857'
         '69457bd8dd067feb70527311c1f72e0c'
         '939f403a71b6e85261d09fc3412269ee')
md5sums=('8bb00d4142259beb11e13473b81c0857'
         '19c825b32f4981ee682180490f761166'
         '939f403a71b6e85261d09fc3412269ee')
md5sums=('8bb00d4142259beb11e13473b81c0857'
         'c91d873539c471dee33d3837a2abc0b2'
         '939f403a71b6e85261d09fc3412269ee')
md5sums=('8bb00d4142259beb11e13473b81c0857'
         '107d52e099c22d372a7e94014b0886e1'
         '939f403a71b6e85261d09fc3412269ee')
md5sums=('8bb00d4142259beb11e13473b81c0857'
         '26f6dac4531e201dd5d77d5667e1ef8b'
         '939f403a71b6e85261d09fc3412269ee')
md5sums=('8bb00d4142259beb11e13473b81c0857'
         '107d52e099c22d372a7e94014b0886e1'
         '939f403a71b6e85261d09fc3412269ee')
md5sums=('8bb00d4142259beb11e13473b81c0857'
         'ad3238617bcfe33b441c1bf9e42b1837'
         '939f403a71b6e85261d09fc3412269ee')
md5sums=('8bb00d4142259beb11e13473b81c0857'
         '9c3e9a172743af440fc154b983fa150c'
         '939f403a71b6e85261d09fc3412269ee')
md5sums=('8bb00d4142259beb11e13473b81c0857'
         '2be93106bad4dc47fd4dc63956a54667'
         '939f403a71b6e85261d09fc3412269ee')
md5sums=('8bb00d4142259beb11e13473b81c0857'
         '948547c08938eb510a2dca572c2af867'
         '939f403a71b6e85261d09fc3412269ee')
