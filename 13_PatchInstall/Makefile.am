bin_PROGRAMS=num_guess
pkgdata_DATA=ru/LC_MESSAGES/num_guess.mo
pkgdatadir = $(localedir)/ru/LC_MESSAGES

AM_CPPFLAGS = -D LOCALEDIR='"$(localedir)"'


TRASH =  messages*.pot num_guess num_guess.o *.po~ ru

ru/LC_MESSAGES/num_guess.mo: ru.po
	mkdir -p `dirname $@`
	msgfmt $< -o $@

ru.po:	messages.pot
	msgmerge -U $@ $<

messages.pot:	num_guess.pot num_guess.c
	xgettext -k_ -c num_guess.c -o messages.new.pot
	cp num_guess.pot messages.pot
	msgmerge -U messages.pot messages.new.pot

clean:
	rm -rf $(TRASH)

gitclean: maintainer-clean
	git clean -fd