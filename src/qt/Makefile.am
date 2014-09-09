include $(top_srcdir)/src/Makefile.include

AM_CPPFLAGS += -I$(top_srcdir)/src \
  -I$(top_builddir)/src/qt \
  -I$(top_builddir)/src/qt/forms \
  $(PROTOBUF_CFLAGS) \
  $(QR_CFLAGS)
bin_PROGRAMS = sidecoin-qt
noinst_LIBRARIES = libsidecoinqt.a
SUBDIRS = $(BUILD_TEST_QT)
DIST_SUBDIRS = test

# sidecoin qt core #
QT_TS = \
  locale/sidecoin_ach.ts \
  locale/sidecoin_af_ZA.ts \
  locale/sidecoin_ar.ts \
  locale/sidecoin_be_BY.ts \
  locale/sidecoin_bg.ts \
  locale/sidecoin_bs.ts \
  locale/sidecoin_ca_ES.ts \
  locale/sidecoin_ca.ts \
  locale/sidecoin_ca@valencia.ts \
  locale/sidecoin_cmn.ts \
  locale/sidecoin_cs.ts \
  locale/sidecoin_cy.ts \
  locale/sidecoin_da.ts \
  locale/sidecoin_de_AT.ts \
  locale/sidecoin_de.ts \
  locale/sidecoin_el_GR.ts \
  locale/sidecoin_en.ts \
  locale/sidecoin_eo.ts \
  locale/sidecoin_es_CL.ts \
  locale/sidecoin_es_DO.ts \
  locale/sidecoin_es_MX.ts \
  locale/sidecoin_es.ts \
  locale/sidecoin_es_UY.ts \
  locale/sidecoin_et.ts \
  locale/sidecoin_eu_ES.ts \
  locale/sidecoin_fa_IR.ts \
  locale/sidecoin_fa.ts \
  locale/sidecoin_fi.ts \
  locale/sidecoin_fr_CA.ts \
  locale/sidecoin_fr.ts \
  locale/sidecoin_gl.ts \
  locale/sidecoin_gu_IN.ts \
  locale/sidecoin_he.ts \
  locale/sidecoin_hi_IN.ts \
  locale/sidecoin_hr.ts \
  locale/sidecoin_hu.ts \
  locale/sidecoin_id_ID.ts \
  locale/sidecoin_it.ts \
  locale/sidecoin_ja.ts \
  locale/sidecoin_ka.ts \
  locale/sidecoin_kk_KZ.ts \
  locale/sidecoin_ko_KR.ts \
  locale/sidecoin_ky.ts \
  locale/sidecoin_la.ts \
  locale/sidecoin_lt.ts \
  locale/sidecoin_lv_LV.ts \
  locale/sidecoin_ms_MY.ts \
  locale/sidecoin_nb.ts \
  locale/sidecoin_nl.ts \
  locale/sidecoin_pam.ts \
  locale/sidecoin_pl.ts \
  locale/sidecoin_pt_BR.ts \
  locale/sidecoin_pt_PT.ts \
  locale/sidecoin_ro_RO.ts \
  locale/sidecoin_ru.ts \
  locale/sidecoin_sah.ts \
  locale/sidecoin_sk.ts \
  locale/sidecoin_sl_SI.ts \
  locale/sidecoin_sq.ts \
  locale/sidecoin_sr.ts \
  locale/sidecoin_sv.ts \
  locale/sidecoin_th_TH.ts \
  locale/sidecoin_tr.ts \
  locale/sidecoin_uk.ts \
  locale/sidecoin_ur_PK.ts \
  locale/sidecoin_uz@Cyrl.ts \
  locale/sidecoin_vi.ts \
  locale/sidecoin_vi_VN.ts \
  locale/sidecoin_zh_CN.ts \
  locale/sidecoin_zh_HK.ts \
  locale/sidecoin_zh_TW.ts

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
  moc_sidecoinaddressvalidator.cpp \
  moc_sidecoinamountfield.cpp \
  moc_sidecoingui.cpp \
  moc_sidecoinunits.cpp \
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

SIDECOIN_MM = \
  macdockiconhandler.mm \
  macnotificationhandler.mm

QT_MOC = \
  sidecoin.moc \
  intro.moc \
  overviewpage.moc \
  rpcconsole.moc

QT_QRC_CPP = qrc_sidecoin.cpp
QT_QRC = sidecoin.qrc

PROTOBUF_CC = paymentrequest.pb.cc
PROTOBUF_H = paymentrequest.pb.h
PROTOBUF_PROTO = paymentrequest.proto

SIDECOIN_QT_H = \
  addressbookpage.h \
  addresstablemodel.h \
  askpassphrasedialog.h \
  sidecoinaddressvalidator.h \
  sidecoinamountfield.h \
  sidecoingui.h \
  sidecoinunits.h \
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
  res/icons/sidecoin.ico \
  res/icons/sidecoin.png \
  res/icons/sidecoin_testnet.ico \
  res/icons/sidecoin_testnet.png \
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

SIDECOIN_QT_CPP = \
  sidecoin.cpp \
  sidecoinaddressvalidator.cpp \
  sidecoinamountfield.cpp \
  sidecoingui.cpp \
  sidecoinunits.cpp \
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
SIDECOIN_QT_CPP += \
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

SIDECOIN_RC = res/sidecoin-qt-res.rc

libsidecoinqt_a_CPPFLAGS = $(AM_CPPFLAGS) $(QT_INCLUDES) \
  -I$(top_srcdir)/src/qt/forms $(QT_DBUS_INCLUDES)
libsidecoinqt_a_SOURCES = $(SIDECOIN_QT_CPP) $(SIDECOIN_QT_H) $(QT_FORMS_UI) \
  $(QT_QRC) $(QT_TS) $(PROTOBUF_PROTO) $(RES_ICONS) $(RES_IMAGES) $(RES_MOVIES)

nodist_libsidecoinqt_a_SOURCES = $(QT_MOC_CPP) $(QT_MOC) $(PROTOBUF_CC) \
  $(PROTOBUF_H) $(QT_QRC_CPP)

BUILT_SOURCES = $(nodist_libsidecoinqt_a_SOURCES)

#Generating these with a half-written protobuf header leads to wacky results.
#This makes sure it's done.
$(QT_MOC): $(PROTOBUF_H)
$(QT_MOC_CPP): $(PROTOBUF_H)

# sidecoin-qt binary #
sidecoin_qt_CPPFLAGS = $(AM_CPPFLAGS) $(QT_INCLUDES) \
  -I$(top_srcdir)/src/qt/forms
sidecoin_qt_SOURCES = sidecoin.cpp
if TARGET_DARWIN
  sidecoin_qt_SOURCES += $(SIDECOIN_MM)
endif
if TARGET_WINDOWS
  sidecoin_qt_SOURCES += $(SIDECOIN_RC)
endif
sidecoin_qt_LDADD = libsidecoinqt.a $(LIBSIDECOIN_SERVER)
if ENABLE_WALLET
sidecoin_qt_LDADD += $(LIBSIDECOIN_WALLET)
endif
sidecoin_qt_LDADD += $(LIBSIDECOIN_CLI) $(LIBSIDECOIN_COMMON) $(LIBLEVELDB) $(LIBMEMENV) \
  $(BOOST_LIBS) $(QT_LIBS) $(QT_DBUS_LIBS) $(QR_LIBS) $(PROTOBUF_LIBS) $(BDB_LIBS)
sidecoin_qt_LDFLAGS = $(QT_LDFLAGS)

# forms/foo.h -> forms/ui_foo.h
QT_FORMS_H=$(join $(dir $(QT_FORMS_UI)),$(addprefix ui_, $(notdir $(QT_FORMS_UI:.ui=.h))))

#locale/foo.ts -> locale/foo.qm
QT_QM=$(QT_TS:.ts=.qm)

.PHONY: FORCE
.SECONDARY: $(QT_QM)

sidecoinstrings.cpp: FORCE
	$(MAKE) -C $(top_srcdir)/src qt/sidecoinstrings.cpp

translate: sidecoinstrings.cpp $(QT_FORMS_UI) $(QT_FORMS_UI) $(SIDECOIN_QT_CPP) $(SIDECOIN_QT_H) $(SIDECOIN_MM)
	@test -n $(LUPDATE) || echo "lupdate is required for updating translations"
	@QT_SELECT=$(QT_SELECT) $(LUPDATE) $^ -locations relative -no-obsolete -ts locale/sidecoin_en.ts

$(QT_QRC_CPP): $(QT_QRC) $(QT_QM) $(QT_FORMS_H) $(RES_ICONS) $(RES_IMAGES) $(RES_MOVIES) $(PROTOBUF_H)
	@cd $(abs_srcdir); test -f $(RCC) && QT_SELECT=$(QT_SELECT) $(RCC) -name sidecoin -o $(abs_builddir)/$@ $< || \
	  echo error: could not build $@
	$(SED) -i.bak -e '/^\*\*.*Created:/d' $@ && rm $@.bak
	$(SED) -i.bak -e '/^\*\*.*by:/d' $@ && rm $@.bak

CLEANFILES = $(BUILT_SOURCES) $(QT_QM) $(QT_FORMS_H) *.gcda *.gcno
