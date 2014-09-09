// Copyright (c) 2011-2014 The Bitcoin developers
// Copyright (c) 2014 Dyffy, Inc.
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef SIDECOINADDRESSVALIDATOR_H
#define SIDECOINADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class SidecoinAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit SidecoinAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** Sidecoin address widget validator, checks for a valid sidecoin address.
 */
class SidecoinAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit SidecoinAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // SIDECOINADDRESSVALIDATOR_H
