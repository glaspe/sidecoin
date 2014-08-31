include $(top_srcdir)/src/Makefile.include

AM_CPPFLAGS += -I$(top_srcdir)/src \
  -I$(top_builddir)/src/qt \
  -I$(top_builddir)/src/qt/forms \
  $(PROTOBUF_CFLAGS) \
  $(QR_CFLAGS)
bin_PROGRAMS = scarycoin-qt
noinst_LIBRARIES = libscarycoinqt.a
SUBDIRS = $(BUILD_TEST_QT)
DIST_SUBDIRS = test

# scarycoin qt core #
QT_TS = \
  locale/scarycoin_ach.ts \
  locale/scarycoin_af_ZA.ts \
  locale/scarycoin_ar.ts \
  locale/scarycoin_be_BY.ts \
  locale/scarycoin_bg.ts \
  locale/scarycoin_bs.ts \
  locale/scarycoin_ca_ES.ts \
  locale/scarycoin_ca.ts \
  locale/scarycoin_ca@valencia.ts \
  locale/scarycoin_cmn.ts \
  locale/scarycoin_cs.ts \
  locale/scarycoin_cy.ts \
  locale/scarycoin_da.ts \
  locale/scarycoin_de_AT.ts \
  locale/scarycoin_de.ts \
  locale/scarycoin_el_GR.ts \
  locale/scarycoin_en.ts \
  locale/scarycoin_eo.ts \
  locale/scarycoin_es_CL.ts \
  locale/scarycoin_es_DO.ts \
  locale/scarycoin_es_MX.ts \
  locale/scarycoin_es.ts \
  locale/scarycoin_es_UY.ts \
  locale/scarycoin_et.ts \
  locale/scarycoin_eu_ES.ts \
  locale/scarycoin_fa_IR.ts \
  locale/scarycoin_fa.ts \
  locale/scarycoin_fi.ts \
  locale/scarycoin_fr_CA.ts \
  locale/scarycoin_fr.ts \
  locale/scarycoin_gl.ts \
  locale/scarycoin_gu_IN.ts \
  locale/scarycoin_he.ts \
  locale/scarycoin_hi_IN.ts \
  locale/scarycoin_hr.ts \
  locale/scarycoin_hu.ts \
  locale/scarycoin_id_ID.ts \
  locale/scarycoin_it.ts \
  locale/scarycoin_ja.ts \
  locale/scarycoin_ka.ts \
  locale/scarycoin_kk_KZ.ts \
  locale/scarycoin_ko_KR.ts \
  locale/scarycoin_ky.ts \
  locale/scarycoin_la.ts \
  locale/scarycoin_lt.ts \
  locale/scarycoin_lv_LV.ts \
  locale/scarycoin_ms_MY.ts \
  locale/scarycoin_nb.ts \
  locale/scarycoin_nl.ts \
  locale/scarycoin_pam.ts \
  locale/scarycoin_pl.ts \
  locale/scarycoin_pt_BR.ts \
  locale/scarycoin_pt_PT.ts \
  locale/scarycoin_ro_RO.ts \
  locale/scarycoin_ru.ts \
  locale/scarycoin_sah.ts \
  locale/scarycoin_sk.ts \
  locale/scarycoin_sl_SI.ts \
  locale/scarycoin_sq.ts \
  locale/scarycoin_sr.ts \
  locale/scarycoin_sv.ts \
  locale/scarycoin_th_TH.ts \
  locale/scarycoin_tr.ts \
  locale/scarycoin_uk.ts \
  locale/scarycoin_ur_PK.ts \
  locale/scarycoin_uz@Cyrl.ts \
  locale/scarycoin_vi.ts \
  locale/scarycoin_vi_VN.ts \
  locale/scarycoin_zh_CN.ts \
  locale/scarycoin_zh_HK.ts \
  locale/scarycoin_zh_TW.ts

QT_FORMS_UI = \
  forms/aboutdialog.ui \
  forms/addressbookpage.ui \
  forms/askpassphrasedialog.ui \
  forms/coincontroldialog.ui \
  forms/editaddressdialog.ui \
  forms/helpmessagedialog.ui \
  forms/intro.ui \
  forms/openuridialog.ui \
  forms/optionsdialog.ui \
  forms/overviewpage.ui \
  forms/receivecoinsdialog.ui \
  forms/receiverequestdialog.ui \
  forms/rpcconsole.ui \
  forms/sendcoinsdialog.ui \
  forms/sendcoinsentry.ui \
  forms/signverifymessagedialog.ui \
  forms/transactiondescdialog.ui

QT_MOC_CPP = \
  moc_addressbookpage.cpp \
  moc_addresstablemodel.cpp \
  moc_askpassphrasedialog.cpp \
  moc_scarycoinaddressvalidator.cpp \
  moc_scarycoinamountfield.cpp \
  moc_scarycoingui.cpp \
  moc_scarycoinunits.cpp \
  moc_clientmodel.cpp \
  moc_coincontroldialog.cpp \
  moc_coincontroltreewidget.cpp \
  moc_csvmodelwriter.cpp \
  moc_editaddressdialog.cpp \
  moc_guiutil.cpp \
  moc_intro.cpp \
  moc_macdockiconhandler.cpp \
  moc_macnotificationhandler.cpp \
  moc_monitoreddatamapper.cpp \
  moc_notificator.cpp \
  moc_openuridialog.cpp \
  moc_optionsdialog.cpp \
  moc_optionsmodel.cpp \
  moc_overviewpage.cpp \
  moc_paymentserver.cpp \
  moc_qvalidatedlineedit.cpp \
  moc_qvaluecombobox.cpp \
  moc_receivecoinsdialog.cpp \
  moc_receiverequestdialog.cpp \
  moc_recentrequeststablemodel.cpp \
  moc_rpcconsole.cpp \
  moc_sendcoinsdialog.cpp \
  moc_sendcoinsentry.cpp \
  moc_signverifymessagedialog.cpp \
  moc_splashscreen.cpp \
  moc_trafficgraphwidget.cpp \
  moc_transactiondesc.cpp \
  moc_transactiondescdialog.cpp \
  moc_transactionfilterproxy.cpp \
  moc_transactiontablemodel.cpp \
  moc_transactionview.cpp \
  moc_utilitydialog.cpp \
  moc_walletframe.cpp \
  moc_walletmodel.cpp \
  moc_walletview.cpp

SCARYCOIN_MM = \
  macdockiconhandler.mm \
  macnotificationhandler.mm

QT_MOC = \
  scarycoin.moc \
  intro.moc \
  overviewpage.moc \
  rpcconsole.moc

QT_QRC_CPP = qrc_scarycoin.cpp
QT_QRC = scarycoin.qrc

PROTOBUF_CC = paymentrequest.pb.cc
PROTOBUF_H = paymentrequest.pb.h
PROTOBUF_PROTO = paymentrequest.proto

SCARYCOIN_QT_H = \
  addressbookpage.h \
  addresstablemodel.h \
  askpassphrasedialog.h \
  scarycoinaddressvalidator.h \
  scarycoinamountfield.h \
  scarycoingui.h \
  scarycoinunits.h \
  clientmodel.h \
  coincontroldialog.h \
  coincontroltreewidget.h \
  csvmodelwriter.h \
  editaddressdialog.h \
  guiconstants.h \
  guiutil.h \
  intro.h \
  macdockiconhandler.h \
  macnotificationhandler.h \
  monitoreddatamapper.h \
  notificator.h \
  openuridialog.h \
  optionsdialog.h \
  optionsmodel.h \
  overviewpage.h \
  paymentrequestplus.h \
  paymentserver.h \
  qvalidatedlineedit.h \
  qvaluecombobox.h \
  receivecoinsdialog.h \
  receiverequestdialog.h \
  recentrequeststablemodel.h \
  rpcconsole.h \
  sendcoinsdialog.h \
  sendcoinsentry.h \
  signverifymessagedialog.h \
  splashscreen.h \
  trafficgraphwidget.h \
  transactiondesc.h \
  transactiondescdialog.h \
  transactionfilterproxy.h \
  transactionrecord.h \
  transactiontablemodel.h \
  transactionview.h \
  utilitydialog.h \
  walletframe.h \
  walletmodel.h \
  walletmodeltransaction.h \
  walletview.h

RES_ICONS = \
  res/icons/add.png \
  res/icons/address-book.png \
  res/icons/scarycoin.ico \
  res/icons/scarycoin.png \
  res/icons/scarycoin_testnet.ico \
  res/icons/scarycoin_testnet.png \
  res/icons/clock1.png \
  res/icons/clock2.png \
  res/icons/clock3.png \
  res/icons/clock4.png \
  res/icons/clock5.png \
  res/icons/configure.png \
  res/icons/connect0_16.png \
  res/icons/connect1_16.png \
  res/icons/connect2_16.png \
  res/icons/connect3_16.png \
  res/icons/connect4_16.png \
  res/icons/debugwindow.png \
  res/icons/edit.png \
  res/icons/editcopy.png \
  res/icons/editpaste.png \
  res/icons/export.png \
  res/icons/filesave.png \
  res/icons/history.png \
  res/icons/key.png \
  res/icons/lock_closed.png \
  res/icons/lock_open.png \
  res/icons/overview.png \
  res/icons/qrcode.png \
  res/icons/quit.png \
  res/icons/receive.png \
  res/icons/remove.png \
  res/icons/send.png \
  res/icons/synced.png \
  res/icons/toolbar.png \
  res/icons/toolbar_testnet.png \
  res/icons/transaction0.png \
  res/icons/transaction2.png \
  res/icons/transaction_conflicted.png \
  res/icons/tx_inout.png \
  res/icons/tx_input.png \
  res/icons/tx_output.png \
  res/icons/tx_mined.png

SCARYCOIN_QT_CPP = \
  scarycoin.cpp \
  scarycoinaddressvalidator.cpp \
  scarycoinamountfield.cpp \
  scarycoingui.cpp \
  scarycoinunits.cpp \
  clientmodel.cpp \
  csvmodelwriter.cpp \
  guiutil.cpp \
  intro.cpp \
  monitoreddatamapper.cpp \
  notificator.cpp \
  optionsdialog.cpp \
  optionsmodel.cpp \
  qvalidatedlineedit.cpp \
  qvaluecombobox.cpp \
  rpcconsole.cpp \
  signverifymessagedialog.cpp \
  splashscreen.cpp \
  trafficgraphwidget.cpp \
  utilitydialog.cpp

if ENABLE_WALLET
SCARYCOIN_QT_CPP += \
  addressbookpage.cpp \
  addresstablemodel.cpp \
  askpassphrasedialog.cpp \
  coincontroldialog.cpp \
  coincontroltreewidget.cpp \
  editaddressdialog.cpp \
  openuridialog.cpp \
  overviewpage.cpp \
  paymentrequestplus.cpp \
  paymentserver.cpp \
  receivecoinsdialog.cpp \
  receiverequestdialog.cpp \
  recentrequeststablemodel.cpp \
  sendcoinsdialog.cpp \
  sendcoinsentry.cpp \
  transactiondesc.cpp \
  transactiondescdialog.cpp \
  transactionfilterproxy.cpp \
  transactionrecord.cpp \
  transactiontablemodel.cpp \
  transactionview.cpp \
  walletframe.cpp \
  walletmodel.cpp \
  walletmodeltransaction.cpp \
  walletview.cpp
endif

RES_IMAGES = \
  res/images/about.png \
  res/images/splash.png \
  res/images/splash_testnet.png

RES_MOVIES = $(wildcard res/movies/spinner-*.png)

SCARYCOIN_RC = res/scarycoin-qt-res.rc

libscarycoinqt_a_CPPFLAGS = $(AM_CPPFLAGS) $(QT_INCLUDES) \
  -I$(top_srcdir)/src/qt/forms $(QT_DBUS_INCLUDES)
libscarycoinqt_a_SOURCES = $(SCARYCOIN_QT_CPP) $(SCARYCOIN_QT_H) $(QT_FORMS_UI) \
  $(QT_QRC) $(QT_TS) $(PROTOBUF_PROTO) $(RES_ICONS) $(RES_IMAGES) $(RES_MOVIES)

nodist_libscarycoinqt_a_SOURCES = $(QT_MOC_CPP) $(QT_MOC) $(PROTOBUF_CC) \
  $(PROTOBUF_H) $(QT_QRC_CPP)

BUILT_SOURCES = $(nodist_libscarycoinqt_a_SOURCES)

#Generating these with a half-written protobuf header leads to wacky results.
#This makes sure it's done.
$(QT_MOC): $(PROTOBUF_H)
$(QT_MOC_CPP): $(PROTOBUF_H)

# scarycoin-qt binary #
scarycoin_qt_CPPFLAGS = $(AM_CPPFLAGS) $(QT_INCLUDES) \
  -I$(top_srcdir)/src/qt/forms
scarycoin_qt_SOURCES = scarycoin.cpp
if TARGET_DARWIN
  scarycoin_qt_SOURCES += $(SCARYCOIN_MM)
endif
if TARGET_WINDOWS
  scarycoin_qt_SOURCES += $(SCARYCOIN_RC)
endif
scarycoin_qt_LDADD = libscarycoinqt.a $(LIBSCARYCOIN_SERVER)
if ENABLE_WALLET
scarycoin_qt_LDADD += $(LIBSCARYCOIN_WALLET)
endif
scarycoin_qt_LDADD += $(LIBSCARYCOIN_CLI) $(LIBSCARYCOIN_COMMON) $(LIBLEVELDB) $(LIBMEMENV) \
  $(BOOST_LIBS) $(QT_LIBS) $(QT_DBUS_LIBS) $(QR_LIBS) $(PROTOBUF_LIBS) $(BDB_LIBS)
scarycoin_qt_LDFLAGS = $(QT_LDFLAGS)

# forms/foo.h -> forms/ui_foo.h
QT_FORMS_H=$(join $(dir $(QT_FORMS_UI)),$(addprefix ui_, $(notdir $(QT_FORMS_UI:.ui=.h))))

#locale/foo.ts -> locale/foo.qm
QT_QM=$(QT_TS:.ts=.qm)

.PHONY: FORCE
.SECONDARY: $(QT_QM)

scarycoinstrings.cpp: FORCE
	$(MAKE) -C $(top_srcdir)/src qt/scarycoinstrings.cpp

translate: scarycoinstrings.cpp $(QT_FORMS_UI) $(QT_FORMS_UI) $(SCARYCOIN_QT_CPP) $(SCARYCOIN_QT_H) $(SCARYCOIN_MM)
	@test -n $(LUPDATE) || echo "lupdate is required for updating translations"
	@QT_SELECT=$(QT_SELECT) $(LUPDATE) $^ -locations relative -no-obsolete -ts locale/scarycoin_en.ts

$(QT_QRC_CPP): $(QT_QRC) $(QT_QM) $(QT_FORMS_H) $(RES_ICONS) $(RES_IMAGES) $(RES_MOVIES) $(PROTOBUF_H)
	@cd $(abs_srcdir); test -f $(RCC) && QT_SELECT=$(QT_SELECT) $(RCC) -name scarycoin -o $(abs_builddir)/$@ $< || \
	  echo error: could not build $@
	$(SED) -i.bak -e '/^\*\*.*Created:/d' $@ && rm $@.bak
	$(SED) -i.bak -e '/^\*\*.*by:/d' $@ && rm $@.bak

CLEANFILES = $(BUILT_SOURCES) $(QT_QM) $(QT_FORMS_H) *.gcda *.gcno
