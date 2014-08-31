// Copyright (c) 2011-2014 The Bitcoin developers
// Copyright (c) 2014 Dyffy, Inc.
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef SCARYCOINADDRESSVALIDATOR_H
#define SCARYCOINADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class ScarycoinAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit ScarycoinAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** Scarycoin address widget validator, checks for a valid scarycoin address.
 */
class ScarycoinAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit ScarycoinAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // SCARYCOINADDRESSVALIDATOR_H
