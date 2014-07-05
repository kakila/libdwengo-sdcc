pkgdata_DATA = common.mk
dist_pkgdata_DATA = Makefile.proj Makefile.topprojdir
CLEANFILES = common.mk

all: common.mk
common.mk: FORCE
	@touch common.mk
	@echo "DWENGOLIB="$(pkglibexecdir) > common.mk
	@echo "DWENGOHEAD="$(pkgincludedir) >> common.mk
	@echo "PK2_BIN="$(PK2_BIN) >> common.mk
	@echo "PK2="$(PK2) >> common.mk
	@echo "SDCC_INCLUDE="$(SDCC_INCLUDE) >> common.mk
	@echo "SDCC_LIBS="$(MCC_LIB) >> common.mk
	@echo "SDAR_L="$(SDAR_L) >> common.mk
	@echo "SDCC_C="$(SDCC_C) >> common.mk
	@echo "CFLAGS ="$(SDCCFLAGS) >> common.mk
	@echo "LFLAGS ="$(SDCCLINKFLAGS) >> common.mk
	@echo 'PROJECT = $${PROJ}' >> common.mk
	@echo "export DWENGOLIB DWENGOHEAD PK2_BIN PK2 SDCC_INCLUDE SDCC_LIBS SDAR_L SDCC_C PROJECT" \
	                                                                  >> common.mk

FORCE:
	@$(RM) common.mk

.PHONY: all FORCE
