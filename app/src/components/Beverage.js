import React, { Component } from 'react';
import styled from 'styled-components';
import { connect } from 'react-redux'
import { brewBeverage } from '../actions/beverage';

const BeverageWrapper = styled.div`
    width: 300px;
    height: 200px;
    display: flex;
    background: #d8d8d8;
    margin: 16px;
    font-size: 40px;
    font-weight: bold;
    justify-content: center;
    align-items: center;
    cursor: pointer;
`;

class Beverage extends Component {
    handleClick = () => this.props.onClick();

    render() {
        return (
            <BeverageWrapper onClick={this.handleClick}>
                {this.props.title}
            </BeverageWrapper>
        );
    }
}

export default connect(
    undefined,
    (dispatch, { id }) => ({
        onClick: () => dispatch(brewBeverage(id)),
    })
)(Beverage);
